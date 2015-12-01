#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <ctype.h>

#include "fmap.h"
#include "fmem.h"

#ifdef __cplusplus
namespace fankux{
#endif

static unsigned int hash_seed = 5381;
static unsigned int hash_rand_seed = 5731;

//private function
static void _reset_header(struct fmap_header*);

static void _release_header(struct fmap_header*);

static struct fmap_node* _find(struct fmap*, const void*, unsigned int*);

static int _expand(struct fmap*, const size_t);

static void _rehash_step(struct fmap*, const unsigned int);

/****************Type Functions *****************/
inline int int_cmp_func(const void* av, const void* bv) {
    int a = (int) av;
    int b = (int) bv;
    return a > b ? 1 : (a < b ? -1 : 0);
}

inline int str_cmp_func(const void* str1, const void* str2) {
    return strcmp((char*) str1, (char*) str2);
}

inline int strcase_cmp_func(void* str1, void* str2) {
    return strcasecmp((char*) str1, (char*) str2);
}

void str_set_func(struct fmap_node* node, void* str) {
    size_t len = strlen((char*) str);
    if (!(node->value = fmalloc(sizeof(len) + 1))) return;
    cpystr(node->value, str, len);
}

void* str_dup_func(const void* str) {
    size_t len = strlen((char*) str);
    char* p = NULL;
    if (!(p = fmalloc(len + 1))) return NULL;
    cpystr(p, str, len);

    return p;
}

inline void str_free_func(void* str) {
    ffree(str);
}

hash_type_t hash_type_lnkboth = {str_hash_func, str_cmp_func, NULL, NULL, NULL, NULL};
hash_type_t hash_type_dupboth = {str_hash_func, str_cmp_func, str_dup_func, str_set_func,
                                 str_free_func, str_free_func};
hash_type_t hash_type_dupkey = {str_hash_func, str_cmp_func, str_dup_func, NULL, str_free_func,
                                NULL};
hash_type_t hash_type_int = {int_hash_func, int_cmp_func, NULL, NULL, NULL, NULL};
hash_type_t hash_type_int_dupval = {int_hash_func, int_cmp_func, NULL, str_set_func, NULL,
                                    str_free_func};

/*************** Hash *********************/
/* Thomas Wang's 32 bit Mix Function */
inline unsigned int int_hash_func(const void* x) {
    unsigned int key = (unsigned int) x;

    key += ~(key << 15);
    key ^= (key >> 10);
    key += (key << 3);
    key ^= (key >> 6);
    key += ~(key << 11);
    key ^= (key >> 16);

    return key;
}

/* djb hash */
inline unsigned int str_hash_func(const void* buf) {
    unsigned int hash = hash_seed;
    unsigned char* p = (unsigned char*) buf;

    while (*p) /* hash = hash * 33 + c */
        hash = ((hash << 5) + hash) + *p++;

    return hash;
}

/* case insensitive hash function (based on djb hash) */
inline unsigned int strcase_hash_func(const void* buf) {
    unsigned int hash = hash_seed;
    unsigned char* p = (unsigned char*) buf;

    while (*p) /* hash * 33 + c */
        hash = ((hash << 5) + hash) + (tolower(*p++));
    return hash;
}

/****************** API Implementations ********************/
static void _reset_header(struct fmap_header* header) {
    header->map = NULL;
    header->size = 0;
    header->size_mask = 0;
    header->used = 0;
}

static void _release_header(struct fmap_header* header) {
    ffree(header->map);
    _reset_header(header);
}

void fmap_init(struct fmap* map) {
    _reset_header(&map->header[1]);
    _reset_header(&map->header[0]);
    map->rehash_idx = -1;
    map->iter_num = 0;
    map->type = &hash_type_lnkboth;
}

/*create a fmap which value linked */
struct fmap* fmap_create() {
    struct fmap* map;
    if (!(map = fmalloc(sizeof(struct fmap)))) return NULL;

    _reset_header(&map->header[1]);
    _reset_header(&map->header[0]);
    map->rehash_idx = -1;
    map->iter_num = 0;
    map->type = &hash_type_lnkboth;

    return map;
}

/* create a fmap which key duplicated, value linked */
struct fmap* fmap_create_dupkey() {
    struct fmap* map;
    if (!(map = fmalloc(sizeof(struct fmap)))) return NULL;

    _reset_header(&map->header[1]);
    _reset_header(&map->header[0]);
    map->rehash_idx = -1;
    map->iter_num = 0;
    map->type = &hash_type_dupkey;

    return map;
}


/* create a fmap which key & value both duplicated */
struct fmap* fmap_create_dupboth() {
    struct fmap* map;
    if (!(map = fmalloc(sizeof(struct fmap)))) return NULL;

    _reset_header(&map->header[1]);
    _reset_header(&map->header[0]);
    map->rehash_idx = -1;
    map->iter_num = 0;
    map->type = &hash_type_dupboth;

    return map;
}

struct fmap* fmap_create_int() {
    struct fmap* map = fmap_create();
    if (map == NULL) return NULL;

    map->type = &hash_type_int;
    return map;
}

struct fmap* fmap_create_dupval() {
    struct fmap* map = fmap_create();
    if (map == NULL) return NULL;

    map->type = &hash_type_int_dupval;
    return map;
}

void fmap_empty(struct fmap* map) {
    struct fmap_node* p, * q;
    for (int j = 0; j < 2; ++j) {
        struct fmap_header* h = &map->header[j];
        for (size_t i = 0; i < h->size; ++i) {
            p = h->map[i];
            while (p) {
                q = p;
                p = p->next;
                fmap_freekey(map, q);
                fmap_freeval(map, q);
                --h->used;
            }
            h->map[i] = NULL;
        }
    }
}

void fmap_free(struct fmap* map) {
    if (map == NULL) return;

    struct fmap_node* p, * q;
    for (int j = 0; j < 2; ++j) {
        struct fmap_header* h = &map->header[j];
        for (size_t i = 0; i < h->size; ++i) {
            p = h->map[i];
            while (p) {
                q = p;
                p = p->next;
                fmap_freekey(map, q);
                fmap_freeval(map, q);
                --h->used;
            }
        }
        ffree(h->map);
    }
    ffree(map);
}

static void _rehash_step(struct fmap* map, const unsigned int step) {
    struct fmap_header* org = &map->header[0];
    struct fmap_header* new = &map->header[1];
    struct fmap_node* p;
    size_t index;
    int i = 0;

    if (!fmap_isrehash(map) || step == 0) return;

    while (i < step) {
        p = org->map[map->rehash_idx];
        while (p && i < step) {
            org->map[map->rehash_idx] = p->next;
            index = new->size_mask & fmap_hash(map, p->key);
            p->next = new->map[index];
            new->map[index] = p;
            p = org->map[map->rehash_idx];

            --org->used;
            ++new->used;
            ++i;
        }
        if (org->map[map->rehash_idx]) continue;

        do {
            /* rehash complete */
            if (++map->rehash_idx >= org->size) {
                map->rehash_idx = -1;

                _release_header(&map->header[0]);
                map->header[0] = map->header[1];
                _reset_header(&map->header[1]);
                //h0 <= h1, release h1

                return;
            }
        } while (!org->map[map->rehash_idx]);
    }
}

static int _expand(struct fmap* map, const size_t len) {
    //is rehash, expand action denied
    if (fmap_isrehash(map)) return 2;

    struct fmap_header* h = &map->header[1];
    struct fmap_node** new = NULL;
    if (!(new = fmalloc(len * sizeof(struct fmap_node*)))) return 0;
    fmemset(new, 0, len * sizeof(struct fmap_node*));

    h->map = new;
    h->size = len;
    h->size_mask = len - 1;
    h->used = 0;

    map->rehash_idx = 0;
    _rehash_step(map, 1);

    return FMAP_OK;
}

/* find the key, the "hash" stores the key hash value */
static struct fmap_node* _find(struct fmap* map, const void* key, unsigned int* hash) {
    struct fmap_header* h = &map->header[0];
    struct fmap_node* p;
    unsigned int hash_code;
    int flag, hflag = 1;

    /* fisrt memeroy allocation */
    if (h->size <= 0) {
        if (!(h->map = fmalloc(FMAP_HEADER_INITIAL_SIZE * sizeof(struct fmap_node*))))
            return 0;
        fmemset(h->map, 0, FMAP_HEADER_INITIAL_SIZE * sizeof(struct fmap_node*));
        h->size = FMAP_HEADER_INITIAL_SIZE;
        h->size_mask = h->size - 1;
    }

    hash_code = fmap_hash(map, key);
    if (hash) *hash = hash_code;

    do {
        p = h->map[(unsigned int) (h->size_mask & hash_code)];
        while (p) {
            if (0 == fmap_cmpkey(map, p->key, key))
                return p;
            p = p->next;
        }
        flag = 0;
        if (fmap_isrehash(map) && hflag) {
            h = &map->header[1];
            flag = 1;
            hflag = 0;
        }
    } while (flag);

    return NULL;
}

/* Add a key-value node at index of 'hash to index'.
** Be sure that key's hash must be equal to p->key's */
int fmap_addraw(struct fmap* map, const unsigned int hash, const void* key, void* value) {
    struct fmap_header* h;
    if (fmap_isrehash(map))
        h = &map->header[1];
    else h = &map->header[0];

    /* fisrt memeroy allocation */
    if (fmap_isempty(map)) {
        if (!(h->map = fmalloc(FMAP_HEADER_INITIAL_SIZE * sizeof(struct fmap_node*))))
            return FMAP_FAILD;
        fmemset(h->map, 0, FMAP_HEADER_INITIAL_SIZE * sizeof(struct fmap_node*));
        h->size = FMAP_HEADER_INITIAL_SIZE;
        h->size_mask = h->size - 1;
    }

    unsigned int index = hash & h->size_mask;
    struct fmap_node* new;
    if (!(new = fmalloc(sizeof(struct fmap_node))))
        return FMAP_FAILD;/* allocate one */

    fmap_setkey(map, new, key);
    /* key never be null if key is string */
    if (map->type->dupkey == str_dup_func && !new->key) {
        ffree(new);
        return FMAP_FAILD;
    }

    fmap_setval(map, new, value);

    new->next = h->map[index];
    h->map[index] = new;

    if (fmap_isrehash(map)) _rehash_step(map, 1);

    if (++h->used >= h->size);
    /* _expand(dict, h->size << 1); */

    return FMAP_OK;
}

int fmap_add(struct fmap* map, const void* key, void* value) {
    unsigned int hash;
    struct fmap_node* p = _find(map, key, &hash);
    if (p) return FMAP_EXIST;//this key already exist, add faild

    return fmap_addraw(map, hash, key, value);
}

inline struct fmap_node* fmap_get(struct fmap* hash, const void* key) {
    return _find(hash, key, NULL);
}

struct fmap_node* fmap_getrand(struct fmap* hash) {
    srand(hash_rand_seed);
    size_t real_size = hash->header[0].used;
    if (fmap_isrehash(hash)) real_size += hash->header[1].used;

    return NULL;//fhash_getat(hash, rand() % real_size);
}

void* fmap_getvalue(struct fmap* map, const void* key) {
    struct fmap_node* node = _find(map, key, NULL);
    if (!node) return NULL;
    return node->value;
}

struct fmap_node* fmap_getslot(struct fmap* map, const void* key) {
    struct fmap_header* h = &map->header[0];

    unsigned int hash_code = fmap_hash(map, key);

    return h->map[h->size_mask & hash_code];
}

int fmap_replace(struct fmap* dict, void* key, void* value) {
    struct fmap_node* p = NULL;
    p = _find(dict, key, NULL);

    if (!p) return 0;

    fmap_freeval(dict, p);
    fmap_setval(dict, p, value);

    return 1;
}

/* change value,if not exist, add new one */
/* !!!!!!!bug!!!!!!! */
int fmap_set(struct fmap* dict, void* key, void* value) {
    unsigned int hash;
    struct fmap_node* p = _find(dict, key, &hash);

    //not exist,then add it to dict
    if (!p) return fmap_addraw(dict, hash, key, value);

    fmap_freeval(dict, p);
    fmap_setval(dict, p, value);

    return FMAP_OK;
}

/* pop a node,
** the memory should be controlled by caller manually */
struct fmap_node* fmap_pop(struct fmap* hash, const void* key) {
    struct fmap_header* h = NULL;
    if (fmap_isrehash(hash)) h = &hash->header[1];
    else h = &hash->header[0];

    unsigned int index = h->size_mask & fmap_hash(hash, key);
    struct fmap_node* p = h->map[index];
    struct fmap_node* q = p;
    while (p) {
        if (!fmap_cmpkey(hash, p->key, key)) break;

        q = p;
        p = p->next;
    }

    //not exist
    if (!p) return NULL;

    if (q != p) q->next = p->next;
    else h->map[index] = p->next;

    --h->used;

    return p;
}

int fmap_remove(struct fmap* hash, const void* key) {
    struct fmap_node* p;
    if (!(p = fmap_pop(hash, key))) return FMAP_NONE;

    fmap_freeval(hash, p);
    fmap_freekey(hash, p);

    return FMAP_OK;
}

/**************** iterator implement ******************/
/* pos is index of node where starting iter */
hash_iter_t* fmap_iter_create(struct fmap* dict, size_t pos) {
    size_t i, level = 0;
    hash_iter_t* iter;
    struct fmap_header* h = &dict->header[0];

    if (pos >= h->used) {
        level = h->size;
        pos -= h->used;
        h = &dict->header[1];
        if (pos >= h->used)
            return NULL; /* out of range */
    }
    if (!(iter = fmalloc(sizeof(hash_iter_t)))) return NULL;

    for (i = 0; i < h->size; ++i) {
        if (!h->map[i]) continue;
        else break;
    }

    iter->no = 0;
    iter->iter_idx = i + level;
    iter->current = h->map[i];

    /* for(i = 0; i < pos; ++i) */
    /* 	iter = fdict_iter_next(dict, iter); */

    return iter;
}

hash_iter_t* fmap_iter_next(struct fmap* hash, hash_iter_t* iter) {
    struct fmap_header* h;
    int flag = 0, hflag = 1;
    size_t i, level = 0;

    if (!iter) return NULL;
    /* no more */
    if (iter->no >= hash->header[0].used + hash->header[1].used - 1) {
        ffree(iter);
        return NULL;
    }

    h = &hash->header[0];
    if (iter->iter_idx >= h->size) {
        level = h->size;
        h = &hash->header[1];
        hflag = 0;
    }

    for (i = iter->iter_idx - level; i < h->size;) {
        if (!h->map[i]) {
            ++i;
            continue;
        }

        if (flag == 1) {
            iter->current = h->map[i];
            iter->iter_idx = i + level;
            ++iter->no;
            return iter;
        }

        if (iter->current->next) {
            iter->current = iter->current->next;
            iter->iter_idx = i + level;
            ++iter->no;
            return iter;
        } else {
            ++i;
            flag = 1;
        }

        if (i == h->size && fmap_isrehash(hash) && hflag) {
            h = &hash->header[1];
            hflag = 0;
            i = 0;
            level = hash->header[0].size;
        }
    }

    /* iteration complete */
    fmap_iter_cancel(hash, iter);
    return NULL;
}

void fmap_iter_cancel(struct fmap* hash, hash_iter_t* iter) {
    __sync_sub_and_fetch(&hash->iter_num, 1);
    ffree(iter);
}

/****************Test use ******************/
void fmap_info_str(struct fmap* hash) {
    printf("rehash_idx:%d; iter_num:%d\n", hash->rehash_idx, hash->iter_num);
    struct fmap_header* h;
    for (int j = 0; j < 2; ++j) {
        h = &hash->header[j];
        printf("header:%d: size:%zu; used:%zu\n", j, h->size, h->used);

        for (int i = 0; i < h->size; ++i) {
            struct fmap_node* p = h->map[i];
            printf("%4d(p:%9d):", i, (int) p);
            while (p) {
                printf("%s:%s->", (char*) p->key, (char*) p->value);
                p = p->next;
            }
            printf("\n");
        }
    }
}

void fmap_info_int(struct fmap* hash) {
    printf("rehash_idx:%zd; iter_num:%zu\n", hash->rehash_idx, hash->iter_num);
    struct fmap_header* h;
    for (int j = 0; j < 2; ++j) {
        h = &hash->header[j];
        printf("h%d: size:%zu; used:%zu\n", j, h->size, h->used);
        for (int i = 0; i < h->size; ++i) {
            struct fmap_node* p = h->map[i];
            printf("%4d(p:%9d):", i, (int) p);
            while (p) {
                printf("%d:%d->", (int) p->key, (int) &p->value);
                p = p->next;
            }
            printf("\n");
        }
    }
}

#ifdef __cplusplus
}
#endif

#ifdef DEBUG_FHASH
int main()
{
    struct fmap * hash = fhash_create();

    fhash_add(hash, "k1", "v1");
    fhash_info_str(hash);

    return 0;
}
#endif /* DEBUG_FHASH */
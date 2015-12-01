#ifndef FMAP_H
#define FMAP_H

#include <inttypes.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
namespace fankux {
#endif

struct fmap_node {
    void* key;
    void* value;
    struct fmap_node* next;
};

struct fmap_header {
    struct fmap_node** map;
    size_t size;
    size_t size_mask;
    size_t used;
};

typedef struct fmap_type {
    unsigned int (* hash_func)(const void* key);

    int    (* cmpkey)(const void* key1, const void* key2);

    void* (* dupkey)(const void* key);

    void   (* dupval)(struct fmap_node* n, void* value);

    void   (* deskey)(void* key);

    void   (* desval)(void* value);
} hash_type_t;

/* max size of hash is (SIZE_MAX-1),
 * because of SIZE_MAX(-1) means memory faild */
struct fmap {
    struct fmap_header header[2];
    ssize_t rehash_idx;   // if rehash needed */
    size_t iter_num;       // iterators' number */
    hash_type_t* type;
};

typedef struct fmap_iter {
    struct fmap_node* current;
    size_t no;           //current node's rank
    size_t iter_idx;
} hash_iter_t;

/****** error code *****/
#define FMAP_FAILD -1 /* memory faild */
#define FMAP_NONE 0  /* no result */
#define FMAP_OK 1
#define FMAP_EXIST 2 /* already exist */

/******************** constants **************************/
#define FMAP_HEADER_INITIAL_SIZE 4
/************************macros***************************/
/* if dupkey is not null,
 * then means string should be duplicated,
 * either the string just linked */
#define fmap_setkey(h, node, key) do{      \
    if((h)->type->dupkey) (node)->key = (h)->type->dupkey(key); else (node)->key = key;     \
}while(0)

#define fmap_setval(h, node, value) do{    \
    if((h)->type->dupval) (h)->type->dupval((node), (value)); else (node)->value = (value); \
}while(0)

/* if deskey is not null,
 * means string had been duplicated,
 * then memeory should be freed,
 * either set the pointer NULL */
#define fmap_freekey(h, node)  do{         \
    if((h)->type->deskey) (h)->type->deskey((node)->key); else (node)->key = NULL;          \
} while (0)

#define fmap_freeval(h, node)  do{         \
    if((h)->type->desval) (h)->type->desval((node)->value); else (node)->value = NULL;      \
} while (0)

#define fmap_cmpkey(h, key1, key2) ((h)->type->cmpkey(key1, key2))
#define fmap_hash(h, key) ((h)->type->hash_func(key))
#define fmap_isrehash(h) ((h)->rehash_idx != -1)
#define fmap_isempty(h) ((h)->header[0].used + (h)->header[1].used == 0)
#define fmap_size(h) ((h)->header[0].used + (h)->header[1].used)

/******************** API ****************************/
void fmap_init(struct fmap* map);

struct fmap* fmap_create();

struct fmap* fmap_create_dupkey();

struct fmap* fmap_create_dupboth();

struct fmap* fmap_create_int();

struct fmap* fmap_create_dupval();

void fmap_empty(struct fmap*);

void fmap_free(struct fmap*);

int fmap_addraw(struct fmap* map, const unsigned int hash_code, const void* key, void* value);

int fmap_add(struct fmap* map, const void* key, void* value);

int fmap_remove(struct fmap* map, const void* key);

struct fmap_node* fmap_pop(struct fmap* map, const void* key);

struct fmap_node* fmap_get(struct fmap* hash, const void* key);

void* fmap_getvalue(struct fmap* map, const void* key);

struct fmap_node* fmap_getslot(struct fmap* map, const void* key);

struct fmap_node* fmap_getrand(struct fmap* map);

int fmap_set(struct fmap* map, void* key, void* value);

int fmap_replace(struct fmap* map, void* key, void* value);

hash_iter_t* fmap_iter_create(struct fmap* map, size_t pos);

hash_iter_t* fmap_iter_next(struct fmap* map, hash_iter_t* iter);

void fmap_iter_cancel(struct fmap* map, hash_iter_t* iter);

void fmap_info_str(struct fmap* map);

void fmap_info_int(struct fmap* map);

/******************* hash type ************************/
extern unsigned int int_hash_func(const void* x);

extern unsigned int str_hash_func(const void* x);

extern unsigned int strcase_hash_func(const void* x);

extern int int_cmp_func(const void* av, const void* bv);

extern int str_cmp_func(const void* str1, const void* str2);

extern int strcase_cmp_func(void* str1, void* str2);

extern void str_set_func(struct fmap_node* n, void* str);

extern void* str_dup_func(const void* str);

extern void str_free_func(void* str);

#ifdef __cplusplus
}
};
#endif

#endif

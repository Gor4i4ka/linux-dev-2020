#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#if _WIN32
#  define C_RED(s)     s
#  define C_GREEN(s)   s
#else
#  define C_RED(s)     "\033[31;1m" s "\033[0m"
#  define C_GREEN(s)   "\033[32;1m" s "\033[0m"
#endif

#ifndef BUF_INIT_CAPACITY
#  define BUF_INIT_CAPACITY 8
#endif

#ifndef BUF_ABORT
#  define BUF_ABORT abort()
#endif

struct buf {
    size_t capacity;
    size_t size;
    char buffer[];
};

#define buf_ptr(v) \
    ((struct buf *)((char *)(v) - offsetof(struct buf, buffer)))

#define buf_free(v) \
    do { \
        if (v) { \
            free(buf_ptr((v))); \
            (v) = 0; \
        } \
    } while (0)

#define buf_size(v) \
    ((v) ? buf_ptr((v))->size : 0)

#define buf_capacity(v) \
    ((v) ? buf_ptr((v))->capacity : 0)

#define buf_push(v, e) \
    do { \
        if (buf_capacity((v)) == buf_size((v))) { \
            (v) = buf_grow1(v, sizeof(*(v)), \
                            !buf_capacity((v)) ? \
                              BUF_INIT_CAPACITY : \
                              buf_capacity((v))); \
        } \
        (v)[buf_ptr((v))->size++] = (e); \
    } while (0)

#define buf_pop(v) \
    ((v)[--buf_ptr(v)->size])

#define buf_grow(v, n) \
    ((v) = buf_grow1((v), sizeof(*(v)), n))

#define buf_trunc(v, n) \
    ((v) = buf_grow1((v), sizeof(*(v)), n - buf_capacity(v)))

#define buf_clear(v) \
    ((v) ? (buf_ptr((v))->size = 0) : 0)

#define TEST(s, x, flag) \
    do { \
        if (x) { \
            printf(C_GREEN("PASS") " %s\n", s); \
	    flag = 0; \
        } else { \
            printf(C_RED("FAIL") " %s\n", s); \
	    flag = -1; \
        } \
    } while (0)


void *
buf_grow1(void *v, size_t esize, ptrdiff_t n);


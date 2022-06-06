#if !defined(MEMORY_DEBUG_H_)
#define MEMORY_DEBUG_H_

#if !defined(TRUE)
#define TRUE 1
#endif
#if !defined(FALSE)
#define FALSE 0
#endif
typedef unsigned char uint8;

#if !defined(F_NO_MEMORY_DEBUG)
	#define F_MEMORY_DEBUG
#endif

#ifdef F_MEMORY_DEBUG

extern void f_debug_memory_init(void (*lock)(void *mutex), void (*unlock)(void *mutex), void *mutex);
extern void *f_debug_mem_malloc(unsigned int size, char *file, unsigned int line);
extern void *f_debug_mem_realloc(void *pointer, unsigned int size, char *file, unsigned int line);
extern void f_debug_mem_free(void *buf);
extern void f_debug_mem_print(unsigned int min_allocs);
extern void f_debug_mem_reset();
extern unsigned char f_debug_memory();

#define malloc(n) f_debug_mem_malloc(n, __FILE__, __LINE__)
#define realloc(n, m) f_debug_mem_realloc(n, m, __FILE__, __LINE__)
#define free(n) f_debug_mem_free(n)

#endif // F_MEMORY_DEBUG

#endif // MEMORY_DEBUG_H_

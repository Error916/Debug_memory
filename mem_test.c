#include <stdio.h>
#include <stdlib.h>
#include "mem_debug.h"

void mutex_lock(void *mutex){ *(int*)mutex = 0; }
void mutex_unlock(void *mutex){ *(int*)mutex = 1; }

int main(int argc, char** argv){
	int *lock = malloc(sizeof(int));
	f_debug_memory_init(mutex_lock, mutex_unlock, lock);
	int *something;
	something = malloc(sizeof(*something) * 100);
	something = realloc(something, 200);
	free(something);

	f_debug_mem_print(0);
	f_debug_memory();

	return 0;
}

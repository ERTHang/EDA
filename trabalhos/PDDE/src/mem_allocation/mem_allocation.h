#ifndef _mem_allocation_h
#define _mem_allocation_h

#include <stddef.h>
#include <stdlib.h>
#include "../error_handling/error_handling.h"

void* alloc_memory(size_t);
void* realloc_memory(void*, size_t);
void* calloc_memory(size_t, size_t);

#endif
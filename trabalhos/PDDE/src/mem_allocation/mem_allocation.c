#include "mem_allocation.h"

void* alloc_memory(size_t size) {
    void* aux;
    aux = malloc(size);
    if (aux == NULL) {
        memory_alloc_error();
    }
    return aux;
}

void* calloc_memory(size_t size, size_t times) {
    void* aux;
    aux = calloc(times, size);
    if (aux == NULL) {
        memory_alloc_error();
    }
    return aux;
}

void* realloc_memory(void* ptr, size_t size) {
    void* aux;
    aux = realloc(ptr, size);
    if (aux == NULL) {
        memory_alloc_error();
    }
    return aux;
}
#include "error_handling.h"

void memory_alloc_error() {
    fprintf(stderr, "Erro ao alocar espaço de memória\n");
    print_trace();
    exit(EXIT_FAILURE);
}

void print_trace(void) {
    void *array[STACK_MAX_RECURSSION];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace(array, STACK_MAX_RECURSSION);
    strings = backtrace_symbols(array, size);

    printf("Obtained %zd stack frames.\n", size);

    for (i = 0; i < size; i++) {
        printf("%s\n", strings[i]);
    }

    free(strings);
}
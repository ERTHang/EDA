#ifndef _error_handling_h
#define _error_handling_h

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_RECURSSION 20

void memory_alloc_error();
void print_trace(void);

#endif
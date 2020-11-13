#ifndef __STDLIB_H__
#define __STDLIB_H__

#include "unistd.h"

struct _heap_header {
	size_t size;
	enum {
		AVAILABLE = 0,
		OCCUPIED = 1
	} status;
	struct _heap_header* prev;
	struct _heap_header* next;
};

struct _heap_header* _heap_list;
#define _heap_header_size (sizeof(struct _heap_header))

void* malloc(size_t);
void free(void*);
void itoa(int, char*, int);
void exit(int);
#endif

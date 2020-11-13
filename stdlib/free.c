#include "stdlib.h"

void free(void* ptr)
{
	if(!ptr) return;
	struct _heap_header* cur = (struct _heap_header*)(ptr - _heap_header_size);
	struct _heap_header* prev = (struct _heap_header*)cur->prev;
	struct _heap_header* next = (struct _heap_header*)cur->next;
	
	cur->status = AVAILABLE;

	if(next && next->status == AVAILABLE) {
		cur->size += (next->size + _heap_header_size);
		cur->next = next->next;
	}
		
	if(prev && prev->status == AVAILABLE) {
		prev->size += (cur->size + _heap_header_size);
		prev->next = cur->next;
	}

	return;
}

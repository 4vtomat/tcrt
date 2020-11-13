#include "stdlib.h"

void* malloc(size_t len)
{
	if(!len) return NULL;
	struct _heap_header* header_tmp = _heap_list;
	while(header_tmp) {
		if(header_tmp->status == AVAILABLE && header_tmp->size >= (_heap_header_size + len)) {
			struct _heap_header* tmp = (struct _heap_header*)((void*)header_tmp + len + _heap_header_size);
			tmp->size = header_tmp->size - len - _heap_header_size;
			tmp->prev = header_tmp;
			tmp->next = header_tmp->next;
			tmp->status = AVAILABLE;
			header_tmp->size = len;
			header_tmp->next = tmp;
			header_tmp->status = OCCUPIED;
			return (void*)((void*)header_tmp + _heap_header_size);
		}
		header_tmp = header_tmp->next;
	}
	return NULL;
}

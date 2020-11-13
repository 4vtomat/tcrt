#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

extern int main(int, char* []);
extern struct _heap_header* _heap_list;

int heap_init()
{
	puts("start initializing heap\n");
	void* tmp = brk(0);
	_heap_list = (struct _heap_header*)tmp;
	size_t len = 1024 * 1024 * 32;
	_brk_cur = brk(tmp + len);
	_heap_list->size = len - _heap_header_size;
	_heap_list->prev = NULL;
	_heap_list->next = NULL;
	char a[15];
	memset(a, 0, sizeof(a));
	itoa(_heap_header_size, a, 10);
	puts("_heap_header size: ");
	puts(a);
	puts("\n");
	memset(a, 0, sizeof(a));
	itoa(_heap_list->size, a, 10);
	puts("heap actual size: ");
	puts(a);
	puts("\n");
	return 0;
}

__attribute__((noreturn)) void tcrt_entry(void)
{
	heap_init();
	asm("pop %rbp \n\t"
			"movq 0(%rsp), %rdi \n\t"
			"leaq 8(%rsp), %rsi \n\t"
			"andq $-16, %rsp \n\t"
			"call main");

	_exit(0);
	for(;;);
}

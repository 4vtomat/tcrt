#include "unistd.h"

extern int main(int, char* []);

__attribute__((noreturn)) void tiny_crt_entry(void)
{
	asm("pop %rbp \n\t"
			"movq 0(%rsp), %rdi \n\t"
			"leaq 8(%rsp), %rsi \n\t"
			"andq $-16, %rsp \n\t"
			"call main");

	exit(0);
	for(;;);
}

#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "assert.h"

int main(int argc, char* argv[])
{
	void* ma = malloc(33554400 - (_heap_header_size << 1));
	if(!ma) return 0;
	puts("ma1\n");
	free(ma);
	char* bk = "\n";
	char buf[20] = {0};
	itoa(__LINE__, buf, 10);
	puts(buf);
	puts(bk);
	puts(__FILE__);
	puts(bk);
	char* cc = "abcde\n";
	char* dd = "args2\n";
	int* kk = (int*)brk(0UL);
	void* gg = (void*)brk((void*)(kk) + 4);
	memset((char*)kk, 0xff, 4);
	*kk -= (1 << 31);
	char buf2[20] = {0};
	itoa(*kk, buf2, 10);
	puts(buf2);
	puts(bk);
	puts(argv[0]);
	puts(bk);
	puts(argv[1]);
	puts(bk);
	// assert(5 < 2);
	char* echo = "/bin/echo";
	const char* argvv[] = {"/bin/echo", "hellooooooo", NULL};
	const char* envp[] = {NULL};
	fork();
	puts(dd);
	execve(echo, argvv, envp);
	return 0;
}

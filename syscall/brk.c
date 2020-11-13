#include "unistd.h"
#include "syscall.h"

void* brk(void* n)
{
	void* ret;
	SYSCALL1(SYS_BRK, ret, n);
	return ret;
}

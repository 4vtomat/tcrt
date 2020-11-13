#include "unistd.h"
#include "syscall.h"

void _exit(int exitCode)
{
	int ret;
	SYSCALL1(SYS_EXIT, ret, exitCode);
}

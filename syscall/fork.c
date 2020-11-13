#include "unistd.h"
#include "syscall.h"

int fork()
{
	int ret = 0;
	SYSCALL(SYS_FORK, ret);
	return ret;
}

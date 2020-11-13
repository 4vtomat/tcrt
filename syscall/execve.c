#include "unistd.h"
#include "syscall.h"

int execve(const char* filename, const char** argv, const char** envp)
{
	int ret;
	SYSCALL3(SYS_EXECVE, ret, (void*)filename, (void*)argv, (void*)envp);
	return ret;
}

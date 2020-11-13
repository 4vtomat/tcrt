#include "unistd.h"
#include "syscall.h"

int write(unsigned int fd, const char* buffer, size_t size)
{
	int ret;
	SYSCALL3(SYS_WRITE, ret, fd, (void*)buffer, size);
	return ret;
}

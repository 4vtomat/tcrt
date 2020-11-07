int write(int fd, const void* buffer, unsigned size)
{
	int ret;
	asm("syscall \n\t"
			:"=a"(ret): "a"(1), "D"(fd), "S"((long)buffer), "d"(size));
	return ret;
}

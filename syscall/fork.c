int fork()
{
	int n = 57;
	int ret = 0;
	asm("syscall"
			:"=a"(ret): "a"(n));
	return ret;
}

void* brk(unsigned long n)
{
	void* ret;
	asm("syscall \n\t"
			:"=a"(ret): "a"(12), "D"(n));
	return ret;
}

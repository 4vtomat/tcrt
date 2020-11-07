int execve(const char* filename, const char* const argv[], const char* const envp[])
{
	int n = 59;
	int ret;
	asm("syscall \n\t"
			: "=a"(ret): "a"(n), "D"((long)filename), "S"((long)argv), "d"((long)envp));
	return ret;
}

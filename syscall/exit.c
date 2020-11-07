void exit(int exitCode)
{
	asm("syscall \n\t"
			:: "a"(60), "D"(exitCode));
}

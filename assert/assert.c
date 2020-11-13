#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

void _assert(int status, const int line, const char* function)
{
	if(!status) {
		char buf[10];
		memset(buf, 0, sizeof(buf));
		itoa(line, buf, 10);
		puts("assertion failed: line ");
		puts(buf);
		puts(" in function ");
		puts(function);
		puts("\n");
		_exit(status);
	}
	return;
}

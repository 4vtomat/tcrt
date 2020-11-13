#include "unistd.h"
#include "string.h"
#include "stdio.h"

int puts(const char* str)
{
	if(!write(stdout, str, strlen(str))) return -1;
	return 0;
}

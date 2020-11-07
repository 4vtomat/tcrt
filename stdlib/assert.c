#include "unistd.h"
#include "stdlib.h"

void assert(int state, const char* msg)
{
	if(!state) {
		write(stdout, msg, strlen(msg));
		exit(1);
	}
}

#include "string.h"

void* memset(void* memory, int value, size_t size)
{
	while(size--) *((char*)memory++) = (unsigned char)value;
}

#include "unistd.h"

void* sbrk(size_t bytes)
{
	void* cur = _brk_cur;
	_brk_cur = brk(cur + bytes);
	return (void*)cur;
}

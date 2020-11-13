#ifndef __ASSERT_H__
#define __ASSERT_H__
#define assert(status) _assert(status, __LINE__, __FUNCTION__)
void _assert(int, const int, const char*);
#endif

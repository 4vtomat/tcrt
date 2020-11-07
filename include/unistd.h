#ifndef __UNISTD_H__
#define __UNISTD_H__

#define NULL (void*)0

typedef int FILE;
#define stdin (FILE)0
#define stdout (FILE)1
#define stderr (FILE)2

// 1
int write(int, const void*, unsigned);
// 12
void* brk(unsigned long);
// 57
int fork();
// 59
int execve(const char*, const char**, const char**);
// 60
void exit(int);

#endif

#ifndef __UNISTD_H__
#define __UNISTD_H__

#define NULL (void*)0
typedef unsigned long size_t;

typedef int FILE;
#define stdin (FILE)0
#define stdout (FILE)1
#define stderr (FILE)2

int write(unsigned int, const char*, size_t);

void* _brk_cur;
void* brk(void*);
void* sbrk(size_t);

int fork();

int execve(const char*, const char**, const char**);

void _exit(int);
#endif

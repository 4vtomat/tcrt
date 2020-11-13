#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#define SYS_WRITE 1
#define SYS_MMAP 9
#define SYS_BRK 12
#define SYS_FORK 57
#define SYS_EXECVE 59
#define SYS_EXIT 60

#define SYSCALL(n, ret) \
asm("syscall" \
		: "=a"(ret): "a"(n))

#define SYSCALL1(n, ret, a1) \
asm("syscall" \
		: "=a"(ret): "a"(n), "D"(a1))

#define SYSCALL2(n, ret, a1, a2) \
asm("syscall" \
		: "=a"(ret): "a"(n), "D"(a1), "S"(a2));

#define SYSCALL3(n, ret, a1, a2, a3) \
asm("syscall" \
		: "=a"(ret): "a"(n), "D"(a1), "S"(a2), "d"(a3))

#define SYSCALL4(n, ret, a1, a2, a3, a4) \
asm("syscall" \
		: "=a"(ret): "a"(n), "D"(a1), "S"(a2), "d"(a3), "r10"(a4))

#define SYSCALL5(n, ret, a1, a2, a3, a4, a5) \
asm("syscall" \
		: "=a"(ret): "a"(n), "D"(a1), "S"(a2), "d"(a3), "r10"(a4), "r8"(a5))

#define SYSCALL6(n, ret, a1, a2, a3, a4, a5, a6) \
asm("syscall" \
		: "=a"(ret): "a"(n), "D"(a1), "S"(a2), "d"(a3), "r10"(a4), "r8"(a5), "r9"(a6))

#endif

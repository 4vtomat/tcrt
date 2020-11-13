.PHONY: clean sys_call_clean std_lib_clean string_clean stdio_clean unistd_clean assert_clean

SYSCALL_PATH := ${SYSCALL_PATH}
STDLIB_PATH := ${STDLIB_PATH}
STRING_PATH := ${STRING_PATH}
STDIO_PATH := ${STDIO_PATH}
UNISTD_PATH := ${UNISTD_PATH}
ASSERT_PATH := ${ASSERT_PATH}

all: dynamic

out := test.o
entry := entry.o
base: _syscall _unistd _string _stdlib _stdio _assert

static: base $(entry) $(out)
	ld -e tcrt_entry -o test $(out) $(entry) $(STDLIB_PATH)/libstdlib.a $(STDIO_PATH)/libstdio.a $(STRING_PATH)/libstring.a $(SYSCALL_PATH)/libsyscall.a $(UNISTD_PATH)/libunistd.a $(ASSERT_PATH)/libassert.a

dynamic: base $(entry) $(out)
	gcc -Wl,-etcrt_entry -o test -nostdlib -fno-builtin -fno-stack-protector $(out) $(entry) -L$(STDLIB_PATH) -lstdlib -L$(SYSCALL_PATH) -lsyscall -L$(STRING_PATH) -lstring -L$(STDIO_PATH) -lstdio -L$(UNISTD_PATH) -lunistd -L$(ASSERT_PATH) -lassert

_syscall:
	make -C $(SYSCALL_PATH)

_stdlib:
	make -C $(STDLIB_PATH)

_string:
	make -C $(STRING_PATH)

_stdio:
	make -C $(STDIO_PATH)

_unistd:
	make -C $(UNISTD_PATH)

_assert:
	make -C $(ASSERT_PATH)

%.o: %.c
	gcc -c -g3 -fPIC -nostdlib -fno-builtin -fno-stack-protector $<

gdb: dynamic
	gdb -q -args ./test test

gdb_static: static
	gdb -q -args ./test test

clean: syscall_clean stdlib_clean string_clean stdio_clean unistd_clean assert_clean
	rm -rf *.o test

syscall_clean:
	make -C $(SYSCALL_PATH) clean

stdlib_clean:
	make -C $(STDLIB_PATH) clean

string_clean:
	make -C $(STRING_PATH) clean

stdio_clean:
	make -C $(STDIO_PATH) clean

unistd_clean:
	make -C $(UNISTD_PATH) clean

assert_clean:
	make -C $(ASSERT_PATH) clean

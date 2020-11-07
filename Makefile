.PHONY: clean sys_call_clean std_lib_clean string_clean

SYSCALL_PATH := ${SYSCALL_PATH}
STDLIB_PATH := ${STDLIB_PATH}
STRING_PATH := ${STRING_PATH}

all: dynamic

out := test.o
entry := entry.o
base: _syscall _string _stdlib 

static: base $(entry) $(out)
	ld -e tiny_crt_entry --whole-archive $(SYSCALL_PATH)/libsyscall.a $(STRING_PATH)/libstring.a $(STDLIB_PATH)/libstdlib.a $(out) $(entry) --no-whole-archive -o test

dynamic: base $(entry) $(out)
	gcc -Wl,-etiny_crt_entry -nostdlib -fno-builtin -fno-stack-protector $(out) $(entry) -L$(STDLIB_PATH) -lstdlib -L$(SYSCALL_PATH) -lsyscall -L$(STRING_PATH) -lstring -o test

_syscall:
	make -C $(SYSCALL_PATH)

_stdlib:
	make -C $(STDLIB_PATH)

_string:
	make -C $(STRING_PATH)

%.o: %.c
	gcc -c -g -fPIC -nostdlib -fno-builtin -fno-stack-protector $<

gdb: all
	gdb -q -args ./test test

gdb_static: static
	gdb -q -args ./test test

clean: syscall_clean stdlib_clean string_clean
	rm -rf *.o test

syscall_clean:
	make -C $(SYSCALL_PATH) clean

stdlib_clean:
	make -C $(STDLIB_PATH) clean

string_clean:
	make -C $(STRING_PATH) clean

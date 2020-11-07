.PHONY: clean

SYSCALLS := $(shell ls *.c)
SYSCALLS := $(patsubst %.c, %.o, $(SYSCALLS))

all: $(SYSCALLS)
	ar -rs libsyscall.a $^
	gcc -shared -o libsyscall.so -Wl,--whole-archive libsyscall.a -Wl,--no-whole-archive

%.o: %.c
	gcc -c -g -fPIC -o $@ -nostdlib -fno-builtin -fno-stack-protector $<

clean:
	rm -rf *.o *.so *.a

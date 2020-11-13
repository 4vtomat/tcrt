.PHONY: clean

SYSCALLS := $(shell ls *.c)
SYSCALLS := $(patsubst %.c, %.o, $(SYSCALLS))

all: $(SYSCALLS)
	ar -rs libsyscall.a $^
	gcc -shared -o libsyscall.so -nostdlib $^

%.o: %.c
	gcc -c -g3 -fPIC -o $@ -nostdlib -fno-builtin -fno-stack-protector $<

clean:
	rm -rf *.o *.so *.a

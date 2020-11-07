.PHONY: clean

ALL_FILES := $(shell ls *.c)
ALL_FILES := $(patsubst %.c, %.o, $(ALL_FILES))
SYSCALL_PATH := ${ROOTDIR}/syscall
STRING_PATH := ${ROOTDIR}/string

all: $(ALL_FILES)
	ar -rs libstdlib.a $^
	gcc -shared -o libstdlib.so $^ $(SYSCALL_PATH)/libsyscall.so $(STRING_PATH)/libstring.so

%.o: %.c
	gcc -c -g -fPIC -nostdlib -fno-builtin -fno-stack-protector -o $@ $<

clean:
	rm -rf *.o *.so *.a

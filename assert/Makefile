.PHONY: clean

ALL_FILES := $(shell ls *.c)
ALL_FILES := $(patsubst %.c, %.o, $(ALL_FILES))

all: $(ALL_FILES)
	ar -rs libassert.a $^
	gcc -shared -o libassert.so -nostdlib $^

%.o: %.c
	gcc -c -g3 -fPIC -o $@ -nostdlib -fno-builtin -fno-stack-protector $<

clean:
	rm -rf *.o *.so *.a

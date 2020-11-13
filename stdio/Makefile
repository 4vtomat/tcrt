.PHONY: clean

ALL_FILES := $(shell ls *.c)
ALL_FILES := $(patsubst %.c, %.o, $(ALL_FILES))

all: $(ALL_FILES)
	ar -rs libstdio.a $^
	gcc -shared -o libstdio.so -nostdlib $^

%.o: %.c
	gcc -c -g3 -fPIC -nostdlib -fno-builtin -fno-stack-protector -o $@ $<

clean:
	rm -rf *.o *.so *.a

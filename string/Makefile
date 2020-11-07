.PHONY: clean

ALL_FILES := $(shell ls *.c)
ALL_FILES := $(patsubst %.c, %.o, $(ALL_FILES))

all: $(ALL_FILES)
	ar -rs libstring.a $^
	gcc -shared -o libstring.so -Wl,--whole-archive libstring.a -Wl,--no-whole-archive

%.o: %.c
	gcc -c -g -fPIC -o $@ -nostdlib -fno-builtin -fno-stack-protector $<

clean:
	rm -rf *.o *.so *.a

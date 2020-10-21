.PHONY: clean

all: ls.o
	gcc -o ls ls.o -lm
ls.o: ls.c
	gcc -c ls.c
clean:
	rm ls.o ls

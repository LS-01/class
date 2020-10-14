CC = gcc
CFLAGS = -std=c99 -Wall -Werror

ncat: ncat.o roman.o
	$(CC) -o ncat ncat.o roman.o

ncat.o : ncat.c
	$(CC) -c ncat.c

roman.o : roman.c
	$(CC) -c roman.c

clean:
	$(RM) -- *.o ncat

.PHONY: all clean

all: sort

CFLAGS = -g -Werror -Wall -O0 -std=c99

clean:
	rm -f sort *.o

sort.o: sort.c
	gcc $(CFLAGS) -c sort.c -o sort.o

sort: sort.o
	gcc sort.o -o sort

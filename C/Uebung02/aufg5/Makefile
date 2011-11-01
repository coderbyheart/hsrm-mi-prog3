CC=gcc
CCFLAGS= -Wall -g -ansi
LD=gcc

PROGS=rot13 rotx
SRC=rot13.c rotx.c

all: $(PROGS)

include make.depend

depend:
	$(CC) -MM $(SRC) > make.depend

clean:
	-/bin/rm *.o $(PROGS)

.SUFFIXES: .o .c .h

%.o : %.c
	$(CC) -c $(CCFLAGS) $< -o $@

%.o : %.c %.h
	$(CC) -c $(CCFLAGS) $< -o $@

rot13: rotx.o

test: all
	@if [ "P vfg gbyy\!" = "`echo "C ist toll\!" | ./rot13`" ]; then echo "OK"; else echo "FAILED"; fi
	@if [ "C ist toll\!" = "`echo "P vfg gbyy\!" | ./rot13`" ]; then echo "OK"; else echo "FAILED"; fi

CC=gcc
CCFLAGS=-Wall -g -ansi
LD=gcc

PROGS=abzaehl
SRC=abzaehl.c

all: $(PROGS)

clean:
	-/bin/rm *.o $(PROGS)

.SUFFIXES: .o .c .h

%.o : %.c
	$(CC) -c $(CCFLAGS) $< -o $@

%.o : %.c %.h
	$(CC) -c $(CCFLAGS) $< -o $@

abzaehl: abzaehl.o

run: abzaehl
	./abzaehl 7 ji ja jen

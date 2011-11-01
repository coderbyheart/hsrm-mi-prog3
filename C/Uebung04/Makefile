CC=gcc
CCFLAGS=-Wall -g -ansi 
LIBFLAGS=-L ./lib -ldllist -lmergesort
LD=gcc

SRC=listargs.c mergesort.c mergesortf.c
PROGS=$(SRC:.c=)

all: progs

progs:
	cd ./lib; make all
	make clean

clean:
	/bin/rm -f *.o $(PROGS)
	cd ./lib; make clean

.SUFFIXES: .o .c .h

%.o : %.c
	$(CC) -c $(CCFLAGS) $< -o $@

%.o : %.c %.h
	$(CC) -c $(CCFLAGS) $< -o $@

listargs : listargs.o
	$(CC) $(CCFLAGS) $< $(LIBFLAGS) -o $@

listargs-run: listargs
	./listargs aaa bbb ccc ddd

mergesort : mergesort.o mergesortcompare.o
	$(CC) $(CCFLAGS) $< mergesortcompare.o $(LIBFLAGS) -o $@

mergesortf : mergesortf.o mergesortcompare.o
	$(CC) $(CCFLAGS) $< mergesortcompare.o $(LIBFLAGS) -o $@

mergesort-run: mergesort mergesortf
	./mergesort Lorem ipsum dolor sit amet consectetur adipiscing elit
	./mergesortf -f sort.txt

run: listargs-run mergesort-run

CC=gcc
CCFLAGS= -Wall -g -ansi
LD=gcc

PROGS=aufg2 aufg3 soundex
SRC=aufg2.c aufg3.c soundex.c

all: $(PROGS)

include make.depend

aufg3: aufg3.o
	$(LD) $(CCFLAGS) -lm aufg3.o -o aufg3

depend:
	$(CC) -MM $(SRC) > make.depend

clean:
	-/bin/rm *.o $(PROGS)

.SUFFIXES: .o .c .h

%.o : %.c
	$(CC) -c $(CCFLAGS) $< -o $@

%.o : %.c %.h
	$(CC) -c $(CCFLAGS) $< -o $@

run: aufg3
	./aufg3 > out.pbm
	display out.pbm
	
soundex-demo: soundex
	./soundex soundex soundeggs flurbel

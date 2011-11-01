CC=gcc
CCFLAGS= -Wall -g -ansi
LD=gcc

PROGS=aufg6 
SRC=my_strcasecmp.c my_tolower.c my_index.c my_rindex.c

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

aufg6: my_strcasecmp.o my_tolower.o my_index.o my_rindex.o

run: all
	./aufg6

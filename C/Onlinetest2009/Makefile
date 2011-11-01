CC=gcc
CCFLAGS=-Wall -g -ansi 

SRC=aufg1.c aufg2.c aufg3.c
PROGS=$(SRC:.c=)

all: $(PROGS)

clean:
	/bin/rm -f *.o $(PROGS)

.SUFFIXES: .o .c .h

%.o : %.c
	$(CC) -c $(CCFLAGS) $< -o $@

%.o : %.c %.h
	$(CC) -c $(CCFLAGS) $< -o $@

run: all
	echo "1 2 3 4 5 6 1 2 3 5 6" | ./aufg1
	echo "1 2 3 3 7 8 8 9 22 22 2 400" | ./aufg2
	echo "Ich gehe jetzt nach esuaH und schreibe diesen txeT!" | ./aufg3

CC=gcc
CCFLAGS=-Wall -g -ansi
LD=gcc

PROGS=split
SRC=split.c

all: $(PROGS)

clean:
	-/bin/rm *.o $(PROGS)

.SUFFIXES: .o .c .h

%.o : %.c
	$(CC) -c $(CCFLAGS) $< -o $@

%.o : %.c %.h
	$(CC) -c $(CCFLAGS) $< -o $@

run: split
	# Middle split 
	./split needle haystackneedlehaystack
	# Middle multi split
	./split needle haystackneedlehaystackhaystackneedlehaystack
	# Incomplete and middle multi split
	./split needle haystackneedlhaystackhaystackneedlehaystackhaystackneedlehaystack
	# Incomplete at start and end
	./split needle neehaystackneedlhaystackhaystacknee
	# Split at end
	./split needle haystackneedlhaystackhaystackneedle
	# Split at start
	./split needle needlehaystack
	# All together
	./split needle haystackneedlehaystack haystackneedlehaystackhaystackneedlehaystack haystackneedlhaystackhaystackneedlehaystackhaystackneedlehaystack neehaystackneedlhaystackhaystacknee haystackneedlhaystackhaystackneedle needlehaystack

split: split.o

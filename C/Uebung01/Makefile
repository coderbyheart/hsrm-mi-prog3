CFLAGS=-ansi -Wall -g

all: 
	make hello
	make groesse
	make rot13
	make io
	make zahlen

run: hello groesse rot13 io
	./hello
	./groesse
	make rot13-run
	make io-run
	make zahlen-run
	make heron-run

clean: 
	make hello-clean
	make groesse-clean
	make rot13-clean
	make io-clean
	make zahlen-clean
	make heron-clean

hello: hello.c
	$(CC) $(CFLAGS) hello.c -o $@

hello-clean:
	rm hello

groesse: groesse.c
	$(CC) $(CFLAGS) groesse.c -o $@

groesse-clean:
	rm groesse

rot13: rot13.c
	$(CC) $(CFLAGS) rot13.c -o $@

rot13-clean:
	rm rot13

rot13-run: rot13
	# Should read: P vfg gbyy!
	echo "C ist toll!" | ./rot13
	# Should read: C ist toll!
	echo "P vfg gbyy!" | ./rot13

io: io.c
	$(CC) $(CFLAGS) io.c -o $@

io-run: io
	echo 0 | ./io
	echo 1 | ./io
	echo 15 | ./io
	echo 16 | ./io
	echo 255 | ./io
	echo 4294967295 | ./io
	echo 4294967296 | ./io

io-clean:
	rm io

zahlen: zahlen.c
	$(CC) $(CFLAGS) zahlen.c -o $@
	
zahlen-run: zahlen
	./zahlen
	
zahlen-clean:
	rm zahlen
	
heron: heron.c
	$(CC) $(CFLAGS) heron.c -o $@
	
heron-run: heron
	echo 2.0 | ./heron
	echo 4.0 | ./heron
	echo 7.0 | ./heron
	echo 9.0 | ./heron
	echo 16.0 | ./heron
	echo 17.0 | ./heron
	./heron 9
	
heron-clean:
	rm heron
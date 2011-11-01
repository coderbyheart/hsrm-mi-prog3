#include <stdio.h>

int main(void) {
	int i , a, b, c=0;
	for (i =0; i < 17; i ++) {
		a = i ^ 10;
		b = 17 / a + 1; /* Division durch null */
		c = a + b + c;
	}
	printf ("Fertig ! Ergebnis = %d\n",c);
	return 0;
}

/*
==3194== Process terminating with default action of signal 8 (SIGFPE)
==3194==  Integer divide by zero at address 0x62BAD1BF
==3194==    at 0x8048414: main (zahlen.c:7)
 */

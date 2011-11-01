#include <stdio.h>

int main(void) {
	char c;
	signed char sc;
	unsigned char usc;
	short s;
	int i;
	long l;
	float f;
	double d;
	long double ld;
	char *cp;
	int *ip;
	printf("c %d\n", sizeof c);
	printf("sc %d\n", sizeof sc);
	printf("usc %d\n", sizeof usc);
	printf("i %d\n", sizeof i);
	printf("l %d\n", sizeof l);
	printf("f %d\n", sizeof f);
	printf("d %d\n", sizeof d);
	printf("ld %d\n", sizeof ld);
	printf("cp %d\n", sizeof cp);
	printf("ip %d\n", sizeof ip);
	return 0;
}

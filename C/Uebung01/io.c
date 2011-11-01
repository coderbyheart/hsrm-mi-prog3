#include <stdio.h>

extern void print_binary(unsigned long long d);
extern void print_decimal(unsigned long long d);

int main(void)
{
	unsigned long long d;
	scanf("%llu", &d);
	printf("Dez: ");
	print_decimal(d);
	printf("\n");
	printf("Bin: ");
	print_binary(d);
	printf("\n");
	return 0; 
}

void print_binary(unsigned long long d)
{
	unsigned long long bittest = d;
	if (d == 0) putchar('0');
	while(bittest > 0) {
		if(d & bittest) {
			putchar('1');
		} else {
			putchar('0');
		}
		bittest>>=1;
	}
}

void print_decimal(unsigned long long d)
{
	unsigned long long e = d / 10;
	if (e > 0) print_decimal(e);
	putchar('0' + d % 10);
}

#include <stdio.h>

extern double heronSqrt(double x);

const float epsilon = 1e-7f;

int main(int argc, char *argv[]) {
	double x;
	if (argc > 1) {
		sscanf (argv[1], "%lf", &x);
	} else {
		scanf("%lf", &x);
	}
	printf("%lf\n", heronSqrt(x));
	return 0;
}

double heronSqrt(double x)
{
	double n, m;
	n = 0;
	m = 0;
	do {
		if (n == 0) {
			n = (1 + x) / 2;
		} else {
			n = m;
		}
		m = (n + (x / n)) / 2;
	} while(n - m > epsilon);
	return m;
}

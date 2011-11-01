#include <stdio.h>

/*
	int i = 2;
	int ia[2];
	short int sa[3] = {1,2,3};
	char ca[6] = "hi";
*/
int main(void)
{
	int i = 2;
	int ia[2];
	short int sa[3] = {1,2,3};
	char ca[6] = "hi";

	printf("i: %d\n", sizeof i);
	printf("ia: %d\n", sizeof ia);
	printf("ia[0]: %d\n", ia[0]);
	printf("sa: %d\n", sizeof sa);
	printf("ca: %d\n", sizeof ca);
	return 0;
}

/*

in main:	   1    ?   ?  1 2 3 hi0000
		i___ ia______ sa____ ca____

auserhalb main:	   1    0   0  1 2 3 hi0000
		i___ ia______ sa____ ca____

*/

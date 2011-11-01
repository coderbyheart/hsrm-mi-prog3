#include "my_index.h"

char *my_index(char *s1, char s2)
{
	while(*s1) {
		if (*s1 == s2) return s1;
		s1++;
	}
	return 0;
}

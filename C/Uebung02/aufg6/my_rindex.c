#include "my_rindex.h"

char *my_rindex(char *s1, char s2)
{
	char *lp = 0;
	while(*s1) {
		if (*s1 == s2) {
			lp = s1;
		}
		s1++;
	}
	return lp;
}

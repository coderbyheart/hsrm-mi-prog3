#include "my_tolower.h"

int my_strcasecmp(char *s1, char *s2)
{
	char c1, c2;
	int diff = 0;
	while(*s1 && *s2) {
		c1 = my_tolower(*s1);
		c2 = my_tolower(*s2);	
		diff = c1 - c2;
		if (diff != 0) return diff;
		s1++;
		s2++;
	}
	if (!*s1 && !*s2) return 0;
	return *s1 ? -1 : 1;
}

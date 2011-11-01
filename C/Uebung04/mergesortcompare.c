#include "mergesortcompare.h"

int compare(void *left, void *right)
{
	char *l = (char *)left;
	char *r = (char *)right;
	while(*l && *r) {
		if (*l == *r) {
			l++;
			r++;
		} else return (*l < *r) ? -1 : 1;
	}
	if (!*l) return -1;
	if (!*r) return 1;
	return 0;
}


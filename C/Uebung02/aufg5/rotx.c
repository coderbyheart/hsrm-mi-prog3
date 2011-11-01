#include "rotx.h"
static int r = 0;

void set_rotate(int n)
{
	r = n;
}

int rotate(int ch)
{
	int enc = ch;
	if (enc >= 'A' && enc <= 'Z') {
		enc = ch - 'A';
		enc = (enc + r) % 26;
		enc = 'A' + enc;
	}
	if (enc >= 'a' && enc <= 'z') {
		enc = ch - 'a';
		enc = (enc + r) % 26;
		enc = 'a' + enc;
	}
	return enc;
}

#include <stdio.h>
#include "rotx.h"

int main(void)
{
	char ch;
	set_rotate(13);
	while ((ch = fgetc(stdin)) != EOF) {
		putc(rotate(ch), stdout);
	}
	return 0; 
}

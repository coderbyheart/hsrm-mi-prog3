#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *args[])
{
	char s[100];
	int i = 0;
	char a;
	char *r, *w;
	while(scanf("%s", s) > 0) {
		a = (char)*s;
		if(isupper(a)) {
			printf("%s ", s);
		} else {
			int len = 0;
			r = s;
			w = s;
			while(*r && !ispunct(*r)) {
				r++;
				len++;
				w++;
			}
			r--;
			len--;
			if(isupper(*r)) {
				while(len >= 0) {
					printf("%c", *r);
					len--;
					r--;
				}
				printf("%s ", w);
			} else {
				printf("%s ", s);
			}
		}
	}
        return 0; 
}

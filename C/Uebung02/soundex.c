#include <stdio.h>
const int SX_LEN = 6;

void soundex();
static char s[7];
static char w[99];

int main(int argc, char *argv[])
{
	int n = 1;
	if(!argc) return;
	for(; n < argc; n++) {
		sscanf(argv[n], "%s", w);
		soundex();
		printf("%d %20s : %s\n", n, w, s);
	}
	return 0;
}

void soundex()
{
	char* wp = w;
	char* sp = s;
	char* sp2 = s;
	char c;
	int n = 0;
	int sn = 0;
	int sx = 0;

	int i = 0;
	for(; i < SX_LEN; i++) {
		s[i] = '0';
	}

	while(*wp && sn < SX_LEN) {
		c = toupper(*wp);
		if (sn == 0) {
			*sp = *wp;
			sp++;
			sn++;
		} else {
			sx = 0;
			switch(c) {
			case 'B':
			case 'F':
			case 'P':
			case 'V':
				sx = '1';
				break;
			case 'C':
			case 'G':
			case 'J':
			case 'K':
			case 'Q':
			case 'S':
			case 'X':
			case 'Z':
				sx = '2';
				break;
			case 'D':
			case 'T':
				sx = '3';
				break;
			case 'L':
				sx = '4';
				break;
			case 'M':
			case 'N':
				sx = '5';
				break;
			case 'R':
				sx = '6';
				break;
			}
			sp2 = sp;
			sp2--;
			if (sx && *sp2 != sx) {
				*sp = sx;
				sp++;
				sn++;
			}
		}
		wp++;
	}
}

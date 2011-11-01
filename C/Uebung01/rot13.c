#include <stdio.h>

int main(void)
{
	char ch, enc;
	while ((ch = fgetc(stdin)) != EOF) {
		enc = ch;
		if (enc >= 'A' && enc <= 'Z') {
			enc = ch - 'A';
			enc = (enc + 13) % 26;
			enc = 'A' + enc;
		}
		if (enc >= 'a' && enc <= 'z') {
			enc = ch - 'a';
			enc = (enc + 13) % 26;
			enc = 'a' + enc;
		}
		putc(enc, stdout);
	}
	return 0; 
}

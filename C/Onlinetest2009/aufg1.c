#include <stdio.h>
#include <ctype.h>

const int MAX_NOTE = 6;
int count[6];

int get_index(int d)
{
	return d - 1;
}

int main(int argc, char *args[])
{
	int d;
	char c;
	do {
		if(scanf("%d%c", &d, &c)) {
			count[get_index(d)]++;
		}
	} while(!iscntrl(c));

	int i;
	for(i = 0; i < MAX_NOTE; i++) {
		printf("%d x Note %d\n", count[i], i + 1);
	}

        return 0; 
}

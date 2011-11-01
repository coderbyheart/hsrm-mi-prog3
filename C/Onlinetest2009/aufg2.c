#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct _listitem {
	struct _listitem *next;
	int number;
};
typedef struct _listitem listitem;
typedef listitem *pi;

int main(int argc, char *args[])
{
	int d;
	char c;
	pi start = NULL;
	pi curr = NULL;
	do {
		scanf("%d%c", &d, &c);
		if (!start) {
			pi num = malloc(sizeof (listitem));
			num->number = d;
			start = num;
			printf("%d ", d);
		} else {
			curr = start;
			int found = 0;
			do {
				if (curr->number == d) {
					printf("[%d] ", d);
					found = 1;
				}
				curr = curr->next;
			} while(curr && !found);
			if (!found) {
				pi newNum = malloc(sizeof (listitem));
				newNum->number = d;
				newNum->next = start;
				start = newNum;
				printf("%d ", d);
			}
		}
	} while(!iscntrl(c));

        return 0; 
}

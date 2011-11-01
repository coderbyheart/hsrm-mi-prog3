/* abzaehl.c */
#include <stdio.h>
#include <stdlib.h>


typedef struct _person person;
struct _person {;
	char *name;
	person *next;
	person *prev;
};
typedef person *pperson;
static pperson start;

int main(int argc, char *argv[])
{
	int debug = 0;
	/* Parameter prüfen */
	if (argc < 3) {
		fprintf(stderr, "Expected at least 2 arguments.\n");
		return 1;
	}
	int s;
	sscanf(argv[1], "%d", &s);	
	if (s < 1) {
		fprintf(stderr, "Number of syllables must be at least 1.\n");
		return 2;
	}
	/* Ring anlegen */
	int i;
	int n = 0;
	pperson last;
	for(i = 2; i < argc; i++, n++) {
		pperson p = malloc(sizeof (person));
		p->name = argv[i];
		if (i == 2) {
			start = p;	
		}
		if (i > 2) {
			last->next = p;
			p->prev = last;
		}
		last = p;
	}
	last->next = start;
	start->prev = last;

	/* Ring durchlaufen */
	person *pperson = start;
	i = 1;
	while(n > 1) {
		if (i % s == 0) {	
			if (debug) printf("-> %s ist raus.\n", pperson->name);
			pperson->prev->next = pperson->next;
			pperson->next->prev = pperson->prev;
			free(pperson);
			n--;
		} else {
			if (debug) {
				printf("%s ", pperson->name);
			}
		}
		pperson = pperson->next;
		i++;
	}
	printf("%s\n", pperson->name);
	free(pperson);
	
	return 0;
}

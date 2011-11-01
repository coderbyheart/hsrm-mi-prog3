#include <stdio.h>
#include <stdlib.h>
#include "lib/libmergesort.h"
#include "mergesortcompare.h"

int main(int argc, char *argv[])
{
	/* Liste aufbauen */
	pdllist l = create();
	pdllist lastl;
	int i;
	for(i = 1; i < argc; i++) {
		lastl = l;
		l = add_last(l, argv[i]);
		del_all(lastl);
	}
	l = mergesort(l, compare);

	/* Ausgeben */
	pdllistitem item = l->first;
	while(item) {
		printf("%s ", (char *)item->data);
		item = item->next;
	}
	printf("\n");
	
	del_all(l);
	return 0;
}

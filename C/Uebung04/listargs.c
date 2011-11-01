#include <stdio.h>
#include <stdlib.h>
#include "lib/libdllist.h"

void delete_handler(void *data)
{
	printf("Eintrag gelöscht: %s\n", (char *)data);
}

void *copy_handler(void *data)
{
	printf("Eintrag kopiert: %s\n", (char *)data);
	return data;
}

int main(int argc, char *argv[])
{
	/* Liste aufbauen */
	pdllist l = create();
	int i;
	pdllist lastl = l;
	for(i = 1; i < argc; i++) {
		l = add_last(l, argv[i]);
		del_all(lastl);
		lastl = l;
	}

	/* Kopieren */
	lastl = l;
	l = copy_custom(l, copy_handler);
	del_all(lastl);

	/* Ausgeben */
	printf("Einträge: \n");
	pdllistitem item = l->first;
	int n = 1;
	while(item) {
		printf("%2d. %s\n", n, (char *)item->data);
		item = item->next;
		n++;
	}
	
	/* Löschen */
	del_all_custom(l, delete_handler);
	return 0;
}

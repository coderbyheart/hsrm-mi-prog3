#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include "lib/libmergesort.h"
#include "mergesortcompare.h"

FILE *fp;

void mergefile()
{
	long maxlen = sysconf(_SC_LINE_MAX);
	char line[maxlen];
	char *pl;
	long len;
	pdllist l = create();
	pdllist lastl;
	void *data;
	while (fgets(line, maxlen, fp) != NULL) {
		len = 0;
		pl = line;
		while(*pl) {
			len++;
			pl++;
		}
		lastl = l;
		data = malloc(len + 1);
		strcpy(data, line);
		l = add_last(l, data);
		del_all(lastl);
	}
	l = mergesort(l, compare);

	/* Ausgeben */
	pdllistitem item = l->first;
	while(item) {
		printf("%s", (char *)item->data);
		free(item->data);
		item = item->next;
	}
	
	del_all(l);
}

int main(int argc, char *argv[])
{
	int opt;
	while ((opt = getopt(argc, argv, "f:")) != -1) {
		switch (opt) {
		case 'f':
			if ((fp = fopen(optarg, "r")) == NULL) {
				fprintf(stderr, "Failed to open file %s\n", argv[0]);
				return EXIT_FAILURE;
			}
			mergefile();
			fclose(fp);
			break;
		default: 
			fprintf(stderr, "Usage: %s -f filename\n", argv[0]);
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}


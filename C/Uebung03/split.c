/* split.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct _splitMatch splitMatch;
struct _splitMatch {
	int num;
	char *text;
	splitMatch *next;
};

typedef struct _splitResult {
	int num;
	splitMatch *match;
} splitResult;

static splitMatch splitMatches[99];
static int cMatches = -1;
static int debug = 0;

splitResult split(char *str, char *delim)
{
	splitResult r = {0};
	if (debug) printf("Splitting %s by %s\n", str, delim);
	splitMatch *lastMatch;
	char *pd = delim;
	char *pstr = str;
	int matchStart = -1;
	int matchEnd = -1;
	int strPos = 0;
	int n = 0;
	int startMatch = 0;
	while(*pstr) {
		if (*pstr == *pd) {
			if (matchStart == -1) {
				matchStart = n;
			}
			pd++;
		} else {
			if (matchStart > -1) {
				if (!*pd) {
					if(matchStart == 0) {
						startMatch = n;
					}
					matchEnd = n;
					if (debug) printf("Match from %d to %d.\n", matchStart, matchEnd);
					r.num++;
					/* Save */
					splitMatch match = {0, malloc((matchStart - strPos) + 1)};
					int ri, rc;
					for(ri = strPos, rc = 0; ri < matchStart; ri++, rc++) {
						match.text[rc] = str[ri];
					}
					match.text[rc] = 0;
					match.num = r.num;
					if (debug) printf("Splitted part: (%2d) %s\n", match.num, match.text);
					/* Copy to global field */
					cMatches++;
					splitMatches[cMatches] = match;
					if (r.num == 1) {
						r.match = &splitMatches[cMatches];
					} else {
						lastMatch->next = &splitMatches[cMatches];
						lastMatch = &splitMatches[cMatches];
					}
					lastMatch = &splitMatches[cMatches];
					strPos = matchEnd;
				} else {
					/* Incomplete match */
					if (debug) printf("Incomplete match.\n");
				}
				matchStart = matchEnd = -1;
				pd = delim;	
			}
		}
		pstr++;
		n++;
	}	
	int endMatch = 0;
	if (matchStart > 0 && !*pd) {
		endMatch = 1;
		if (debug) printf("EndMatch!\n");
		n = matchStart;
	}
	if(startMatch) {
		if (debug) printf("StartMatch!\n");
		strPos = startMatch;
	}
	if (r.num > 0 || endMatch || startMatch) {
		/* Save last string part */
		splitMatch match = {startMatch ? r.num : r.num + 1, malloc((n - strPos) + 1)};
		int ri, rc;
		for(ri = strPos, rc = 0; ri < n; ri++, rc++) {
			match.text[rc] = str[ri];
		}
		match.text[rc] = 0;
		if (debug) printf("Save last part: (%2d) %s\n", match.num, match.text);
		/* Copy to global field */
		if (!startMatch) cMatches++;
		splitMatches[cMatches] = match;
		if (endMatch) {
			r.num++;
			r.match = &splitMatches[cMatches];
		} else if(startMatch) {
			r.match = &splitMatches[cMatches];
		} else { 
			lastMatch->next = &splitMatches[cMatches];
		}
	}
	return r;
}

void clear(splitResult r)
{
	if (r.num <= 0) return;
	splitMatch *m = r.match;
	do {
		free(m->text);
	} while((m = m->next));
}

int main(int argc, char *argv[])
{
	int i;
	if (argc < 3) {
		if (debug) printf(stderr, "Must provide at least 2 strings.\n");
		return 1;
	}
	for(i = 2; i < argc; i++) {
		splitResult r = split(argv[i], argv[1]);
		printf("%s splitted %s %d times.\n", argv[1], argv[i], r.num);
		/* Print matches */
		if (r.num > 0) {
			printf("Matches:\n");
			splitMatch *m = r.match;
			do {
				printf("(%2d) %s\n", m->num, m->text);
			} while((m = m->next));
		}
		clear(r);
	}
	return 0;
}

/* libmergesort.c */

#include <stdlib.h>
#include <stdio.h>
#include "libdllist.h"
#include "libmergesort.h"

pdllist merge(pdllist left, pdllist right, int (* compare)(void *, void *))
{
	pdllist nl = create();
	pdllist lastl;
	pdllistitem l = left->first;
	pdllistitem r = right->first;
	if(left->size && right->size) {
		do {
			lastl = nl;
			int result = compare(l->data, r->data);
			if (result < 0) {
				nl = add_last(nl, l->data);
				l = l->next;
			} else {
				nl = add_last(nl, r->data);
				r = r->next;
			}
			del_all(lastl);
		} while(l && r);
	}
	while(l) {
		lastl = nl;
		nl = add_last(nl, l->data);
		l = l->next;
		del_all(lastl);
	}
	while(r) {
		lastl = nl;
		nl = add_last(nl, r->data);
		r = r->next;
		del_all(lastl);
	}
	del_all(left);
	del_all(right);
	return nl;
}

pdllist mergesort(pdllist l, int (* compare)(void *, void *))
{
	if (l->size <= 1) return l; 
	pdllist left = create();
	pdllist right = create();
	int half = l->size / 2;
	int i;
	pdllistitem item = l->first;
	pdllist lastleft, lastright;
	for(i = 0; i < l->size; i++) {
		if (i < half) {
			lastleft = left;
			left = add_last(left, item->data);
			del_all(lastleft);
		} else {
			lastright = right;
			right = add_last(right, item->data);
			del_all(lastright);
		}
		item = item->next;
	}
	pdllist nl = merge(mergesort(left, compare), mergesort(right, compare), compare);
	del_all(l);
	return nl;
}

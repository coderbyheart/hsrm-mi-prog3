/* libdllist.c */

#include "libdllist.h"
#include <stdlib.h>
#include <stdio.h>

pdllist create()
{
	pdllist l = malloc(sizeof (dllist));
	l->size = 0;
	l->first = 0;
	l->last = 0;
	return l;
}

pdllistitem create_item(void *data)
{
	pdllistitem i = malloc(sizeof (dllistitem));
	i->data = data;
	i->next = 0;
	i->prev = 0;
	return i;
}

pdllist add(pdllist l, void *data)
{
	pdllist nl = copy(l);
	pdllistitem i = create_item(data);
	if (nl->first) {
		nl->first->prev = i;
	}
	nl->first = i;
	if (!nl->last) nl->last = i;
	nl->size++;
	return nl;

}

pdllist add_ith(pdllist l, void *data, int n)
{
	if (!l->first) return add(l, data);
	if (n == 0) return add(l, data);
	pdllist nl = copy(l);
	int m;
	pdllistitem c = nl->first;
	for(m = 0; m <= n && c->next; n++) {
		c = c->next;
	}
	pdllistitem i = create_item(data);
	c->next->prev = i;
	c->next = i;
	if (c == nl->last) nl->last = i;
	nl->size++;
	return nl;
}

pdllist add_last(pdllist l, void *data)
{
	if (!(l->first)) {
		return add(l, data);
	}
	pdllist nl = copy(l);
	pdllistitem i = create_item(data);
	i->prev = nl->last;
	nl->last->next = i;
	nl->last = i;
	nl->size++;
	return nl;
}

void dummy_delete_callback(void *data) {}
void *dummy_copy_callback(void *data) 
{
	return data;
}

pdllist copy(pdllist l)
{
	pdllist nl = create();
	if (l->first) {
		pdllistitem i = l->first;
		int n = 0;
		do {
			pdllistitem ni = create_item(i->data);
			if (n == 0) {
				nl->first = ni;
				nl->last = ni;
			} else {
				ni->prev = nl->last;
				nl->last->next = ni;
				nl->last = ni;
			}
			n++;
			i = i->next;
			nl->size++;
		} while(i);
	}
	return nl;
}

pdllist copy_custom(pdllist l, void *(* custom)(void *))
{
	pdllist nl = create();
	if (l->first) {
		pdllistitem i = l->first;
		int n = 0;
		do {
			pdllistitem ni = create_item(custom(i->data));
			if (n == 0) {
				nl->first = ni;
				nl->last = ni;
			} else {
				ni->prev = nl->last;
				nl->last->next = ni;
				nl->last = ni;
			}
			n++;
			i = i->next;
		} while(i);
	}
	return nl;
}

void del_all_custom(pdllist l, void (* custom)(void *)) 
{
	if (l->first) {
		pdllistitem i = l->first;
		pdllistitem next;
		int n = 0;
		do {
			if (n > 0) i = next;
			custom(i->data);
			next = i->next;
			free(i);
			n++;
		} while(next);
	}
	free(l);
}

void del_all(pdllist l)
{
	return del_all_custom(l, dummy_delete_callback);
}

/* libdllist.h */
#ifndef LIBDLLIST_H
#define LIBDLLIST_H
typedef struct _dllistitem dllistitem;
struct _dllistitem {
	void *data;
	dllistitem *next;
	dllistitem *prev;
};
typedef dllistitem *pdllistitem;

typedef struct _dllist dllist;
struct _dllist {
	dllistitem *first;
	dllistitem *last;
	int size;
};
typedef dllist *pdllist;

pdllist create();
pdllistitem create_item(void *data);
pdllist add(pdllist l, void *data);
pdllist add_ith(pdllist l, void *data, int i);
pdllist add_last(pdllist l, void *data);
pdllist copy(pdllist l);
pdllist copy_custom(pdllist l, void *(* custom)(void *));
void del_all(pdllist l);
void del_all_custom(pdllist l, void (* custom)(void *));
#endif

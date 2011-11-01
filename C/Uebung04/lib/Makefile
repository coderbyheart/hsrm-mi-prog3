DEPCC=$(CC) -MM
CFLAGS=-g

FILES=libdllist.c libmergesort.c
OBJS=$(FILES:.c=.o)
DEPS=depend
LIB=$(FILES:.c=.a)

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) -rv $@ $(OBJS)

-include $(DEPS)

$(OBJS):

$(DEPS):
	$(DEPCC) $(FILES) >$(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) 

clobber: clean
	rm -f $(LIB) *~


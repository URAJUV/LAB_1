CC=gcc
CFLAGS=-I.
objects :kruskal prim

all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

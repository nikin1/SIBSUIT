all: OBJECTS libsort1.a libsort2.a sort

OBJECTS: main.c sort_bubble.c sort_simple_choise.c
	gcc -c *.c

libsort1.a: sort_simple_choise.o
	ar r libsort1.a sort_simple_choise.o
	ranlib libsort1.a

libsort2.a: sort_bubble.o
	ar r libsort2.a sort_bubble.o
	ranlib libsort2.a

sort: main.o libsort1.a libsort2.a
	gcc -o sort main.o libsort1.a libsort2.a

clean:
	rm *.o

.PHONY: all clean sort libsort1.a libsort2.a OBJECTS
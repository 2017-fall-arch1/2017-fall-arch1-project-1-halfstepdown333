all: BSTDEMO

CFLAGS=-g -O3



BSTDEMO: BST.o BSTDEMO.o
	cc -o $@ $^

BST.o: BST.c BST.h
	cc -c $(CFLAGS) BST.c

BSTDEMO.o: BSTDEMO.c BST.h
	cc -c $(CFLAGS) BSTDEMO.c

clean:
	rm -f *.o BSTDEMO
demo: BSTDEMO
	(echo first;echo"second line";echo"third and last") | ./BSTDEMO

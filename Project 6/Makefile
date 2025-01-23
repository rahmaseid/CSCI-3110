CC=g++
CFLAGS=-g

## Create the executable Run
main: wordEntry.o bst.o main.o
	$(CC) wordEntry.o bst.o main.o -o main 

wordEntry.o:wordEntry.cpp
	$(CC) $(CFLAGS) -c wordEntry.cpp

bst.o:bst.cpp
	$(CC) $(CFLAGS) -c bst.cpp

main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o

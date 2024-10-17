CC=g++
CFLAGS=-g

## Create the executable Run
main:student.o	roster.o main.o
	$(CC) student.o roster.o main.o -o main 

student.o:student.cpp
	$(CC) $(CFLAGS) -c student.cpp

roster.o:roster.cpp
	$(CC) $(CFLAGS) -c roster.cpp

main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o

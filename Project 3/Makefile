CC=g++
CFLAGS=-g

## Create the executable Run
main: flightMap.o type.o main.o
	$(CC) flightMap.o type.o main.o -o main 

flightMap.o:flightMap.cpp
	$(CC) $(CFLAGS) -c flightMap.cpp

type.o:type.cpp
	$(CC) $(CFLAGS) -c type.cpp

main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o
.PHONY:clean all
CC=g++
CFLAGS=-Wall -g -lpthread -std=c++11
BIN=pthread
pthread:1.o
	$(CC) $(CFLAGS) $< -o $@
1.o:1.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(BIN)

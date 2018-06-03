.PHONY:clean all
BIN=1 2
all:$(BIN)
%.o:%.cpp
	gcc -Wall -g -c $< -o $@
1:1.o
	gcc -Wall -g $^ -o $@
2:2.o
	gcc -Wall -g $^ -o $@

clean:
	rm -f *.o $(BIN)

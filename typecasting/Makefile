.PHONY:clean all
BIN=1 2
all:$(BIN)
%.o:%.cpp
	g++ -Wall -g -c $< -o $@
1:1.o
	g++ -Wall -g $^ -o $@
2:2.o
	g++ -Wall -g $^ -o $@

clean:
	rm -f *.o $(BIN)

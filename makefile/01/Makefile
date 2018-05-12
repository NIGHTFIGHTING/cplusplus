.PHONY:clean
OBJECTS=main.o add.o sub.o
main:$(OBJECTS)
	g++ -Wall -g $^ -o $@ 
main.o:main.c
	g++ -Wall -g -c $< -o $@	
add.o:add.c
	g++ -Wall -g -c $< -o $@	
sub.o:sub.c
	g++ -Wall -g -c $< -o $@

clean:
	rm -f main $(OBJECTS)

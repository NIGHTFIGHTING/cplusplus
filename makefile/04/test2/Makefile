CC	= gcc
CFLAGS	= -Wall -g
BIN	= test2
OBJS	= test2.o
.PHONY:all clean print
all:print $(BIN)
print:
	@echo "----- make all in $(PWD) -----"
$(BIN):$(OBJS)
	$(CC) $(OBJS) -o $@
%.o:%.c
	$(CC) -c $< -o $@
clean:
	@echo "----- make clean in $(PWD) -----"
	rm -f $(BIN) $(OBJS)

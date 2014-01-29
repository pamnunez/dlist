CFLAGS=-Wall -g -D_DEBUG
CC=gcc
OBJ=list.o main.o
HEADERS=list.h

list : $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^

list.o : list.c
	$(CC) $(CFLAGS) -c list.c

.PHONY : clean
clean :
	rm -rf list $(OBJ)

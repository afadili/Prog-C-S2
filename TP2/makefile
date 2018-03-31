CC = gcc
CFLAGS = -Wall -g
LDFLAGS =

SRC = $(wildcard */*.c) $(wildcard *.c)
OBJS = $(SRC:.c=.o)
AOUT = main 

all : $(AOUT)

run:
	./main

main : $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	@rm *.o */*.o

cleaner : clean
	@rm $(AOUT)

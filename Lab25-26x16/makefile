#!usr\bin\bash
CC = gcc
LD = gcc
CCFLAGS = -g -Wall -pedantic -std=c99
LDFLAGS = 
OBJ = menu.o empty.o
.SUFFIXES: .c .o 
menu: $(OBJ)
	$(LD) $(LDFLAGS) -o menu $(OBJ)
menu.o: menu.c empty.o
.c.o :
	$(CC) $(CCFLAGS) -c $< -o $@
empty.c: data.h
clean:
	rm -f *.o prog
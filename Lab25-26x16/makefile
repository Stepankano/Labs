#!usr\bin\bash
CC = gcc
LD = gcc
CCFLAGS = -g -Wall -pedantic -std=c99
LDFLAGS = 
OBJ = menu.o output.c push_pop.c sort.c
.SUFFIXES: .c .o 
menu: $(OBJ)
	$(LD) $(LDFLAGS) -o menu $(OBJ)
menu.o: menu.c 
output.o: output.c 
push_pop.o: push_pop.c 
sort.o: sort.c 
.c.o :
	$(CC) $(CCFLAGS) -c $< -o $@
output.c: data.h
push_pop.c: data.h
sort.c: data.h
clean:
	rm -f *.o prog
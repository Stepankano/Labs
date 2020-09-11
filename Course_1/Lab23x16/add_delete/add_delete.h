#ifndef ADD_DELETE_H
#define ADD_DELETE_H
#include "../data.h"

cell *create(int);
cell *destroy(cell *);

void add(cell *, int);

void delete (cell *, cell *, int);

#endif
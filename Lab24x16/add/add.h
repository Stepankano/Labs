#ifndef ADD_H
#define ADD_H
#include "../data.h"

cell *add_int(cell *, int);
cell *add_char(cell *, char);

/*
I decided to develop my algorithm for converting to a tree (at least it works better than Rutishauser). 
The point is to create a tree from a leaf, not a root, then, if the expression is linear, that is, without parentheses and distortions of priority, the tree grows upward, otherwise, it grows downward. 
When counting, a recursive function is used.
It`s work for infics notation.
*/

#endif
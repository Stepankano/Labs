#ifndef STRUCTURES_H
#define STRUCTURES_H

#define cell struct tree_cell
#define coup struct couple_cell_int

typedef struct tree_cell
{
    cell *left;
    cell *right;
    cell *parent;
    int value;
}this_cell;

typedef struct couple_cell_int
{
    cell _cell;
    int _int;
    int root_bool;
}this_coup;


#endif 
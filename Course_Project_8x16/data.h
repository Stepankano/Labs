#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define eps 0.00001
#define Sign(new_val) (new_val == 1) ? AARD : (new_val == 2) ? QUEN : (new_val == 3) ? IGNI : (new_val == 4) ? YRDEN : AXII

#define Cret(tmp, type)                   \
    tmp = (type *)malloc(sizeof(type *)); \
    if (!tmp)                             \
    {                                     \
        printf("Out of memory\n");        \
    }

enum sign // Ведьмачьи знаки)))
{
    AARD,
    QUEN,
    IGNI,
    YRDEN,
    AXII
} value;

typedef struct cell
{
    enum sign value;

    struct cell *next;
    struct cell *prev;
} cell;

void std_print(struct cell *);
void std_size(struct cell *);
struct cell *std_insert(struct cell *, enum sign);
struct cell *std_delete(struct cell *, enum sign);
struct cell *unstd_act(struct cell *, enum sign);
#endif
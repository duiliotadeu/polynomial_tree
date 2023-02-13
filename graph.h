#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int coordX;
    int coordY;
} edge;

typedef struct
{
    bool valid;
    int num;
} vertex;

typedef struct
{
    vertex *vertex;
} graph;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

struct cell {
    int alive; // We check if it's currently alive
    int dying; // We check if it's dying to prevent other deaths or forgotten cell creation
    int justBorn; // We check if the cell is in the process of being created
};

typedef struct cell cell;


cell** createMatrix(int nbRows, int nbCols);
int initCells(cell** matrix, int nbRows, int nbCols);
void printMatrix(cell** matrix, int nbRows, int nbCols);
int lookAround(cell** matrix, int nbRows, int nbCols, int posX, int posY);
int checkMatrix(cell** matrix, int nbRows, int nbCols);

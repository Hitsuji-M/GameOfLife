#include "gol.h"

cell** createMatrix(int nbRows, int nbCols) {
    cell** matrix = (cell**) calloc(nbRows, sizeof(cell*));
    for (int i = 0; i < nbRows; i++) {
        matrix[i] = (cell*) calloc(nbCols, sizeof(cell));
    }
    return matrix;
}

void initCells(cell** matrix, int nbRows, int nbCols) {
    for (int i =0; i < nbRows; i++) {
        for (int j = 0; j < nbCols; j++) {
            (matrix[i]+j)->alive = ((rand() % 3 - 1) == 1 ? 1 : 0);
        }
    }

}

void printMatrix(cell** matrix, int nbRows, int nbCols) {
    for (int i = 0; i < nbRows; i++) {
        for (int j = 0; j < nbCols; j++) {
            printf("%s ", matrix[i][j].alive ? "■" : "□");
        }
        printf("\n");
    }
}

int lookAround(cell** matrix, int nbRows, int nbCols, int posX, int posY) {
    int count  = 0;
    int startX = (posX - 1 < 0) ? posX : posX - 1;
    int startY = (posY - 1 < 0) ? posY : posY - 1;
    int endX   = (posX + 1 > nbRows-1) ? posX : posX + 1;
    int endY   = (posY + 1 > nbCols-1) ? posY : posY + 1;

    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            if (i == posX && j == posY) continue;
            cell currCell = matrix[i][j];
            if (i > posX || (j > posY && i >= posX)) {
                if (currCell.alive) count++;
            }
            else if ((currCell.alive && !currCell.justBorn) || (!currCell.alive && currCell.dying)) count++;
        }
    }
    return count;
}

int checkMatrix(cell** matrix, int nbRows, int nbCols) {
    int count = 0;
    int nbNeig = 0;
    cell* currCell;

    for (int i = 0; i < nbRows; i++) {
        for (int j = 0; j < nbCols; j++) {
            currCell = matrix[i]+j;
            currCell->dying = FALSE;
            currCell->justBorn = FALSE;

            nbNeig = lookAround(matrix, nbRows, nbCols, i, j);
            if (currCell->alive) {
                if (nbNeig < 2 || nbNeig > 3) {
                    currCell->alive = FALSE;
                    currCell->dying = TRUE;
                }
                else {
                    count++;
                }
            }
            else {
                if (nbNeig == 3) {
                    currCell->alive = TRUE;
                    currCell->justBorn = TRUE;
                    count++;
                }
            }
        }
    }
    return count;
}
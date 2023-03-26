#include "gol.h"

int main(int argc, char* argv[]) {
    int nbRows = 50;
    int nbCols = 50;
    unsigned int seed = 0;
    int nbGen = 0;
    int population = 0;

    if (argc == 2) {
        seed = (unsigned int) atoi(argv[1]);
    }
    else if (argc > 2) {
        fprintf(stderr, "One argument maximum : seed number (default use time)\n");
        return 1;
    }
    else {
        seed = (unsigned int) time(NULL);
    }

    srand(seed);
    cell** matrix = createMatrix(nbRows, nbCols);
    initCells(matrix, nbRows, nbCols);

    while (TRUE) {
        printMatrix(matrix, nbRows, nbCols);
        printf("Generation : %d /// Population : %d\n", ++nbGen, population);
        sleep(1);
        system("clear");
        population = checkMatrix(matrix, nbRows, nbCols);
    }

    return 0;
}
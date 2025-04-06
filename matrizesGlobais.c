#include <stdlib.h>
#include <string.h>

#include "matrizesGlobais.h"
#include "variaveisGlobais.h"

int** sudokuCompleto = NULL;
int** sudokuIncompleto = NULL;

void inicializarMatrizes() {
    sudokuCompleto = (int**)malloc(N*sizeof(int *));  // Matrizes do sudoku alocadas dinamicamente
    sudokuIncompleto = (int**)malloc(N*sizeof(int *));

    for(int i = 0; i < N; i++) {
        sudokuCompleto[i] = (int *)calloc(N, sizeof(int));
        sudokuIncompleto[i] = (int *)calloc(N, sizeof(int));
    }
}

void finalizarMatrizes() {
    for(int i = 0; i < N; i++) {    // Matrizes liberadas
        free(sudokuCompleto[i]);
        free(sudokuIncompleto[i]);
    }

    free(sudokuCompleto);
    free(sudokuIncompleto);
}
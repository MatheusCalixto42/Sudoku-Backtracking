#include <stdlib.h>
#include <string.h>

#include "gerarSudoku.h"
#include "jogar.h"

int main() {
     
    int** sudokuCompleto = (int**)malloc(N*sizeof(int *));  // Matriz alocada dinamicamente
    int** sudokuIncompleto = (int**)malloc(N*sizeof(int *));

    for(int i = 0; i < N; i++) {
        sudokuCompleto[i] = (int *)malloc(N*sizeof(int));
        sudokuIncompleto[i] = (int *)malloc(N*sizeof(int));

        memset(sudokuCompleto[i], 0, sizeof(sudokuCompleto));
    }

    gerarSudoku(sudokuCompleto, sudokuIncompleto);

    jogar(sudokuCompleto, sudokuIncompleto);

    for(int i = 0; i < N; i++) {
        free(sudokuCompleto[i]);
        free(sudokuIncompleto[i]);
    }

    free(sudokuCompleto);
    free(sudokuIncompleto);

    return 0;
}
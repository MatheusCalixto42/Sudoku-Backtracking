#ifndef GERARSUDOKU_H
#define GERARSUDOKU_H

#define N 9
#define NUM_VAZIOS 15

void primeiraLinha(int** tab);

int verificarEscolha(int** tab, int num, int linha, int coluna);

void gerarCandidatos(int** tab, int* c, int linha, int coluna, int* numCandidatos);

void sudokuBT(int** tab, int linha, int coluna);

void gerarSudoku(int** tabCompleto, int** tabIncompleto);

void gerarEspacosVazios(int** tabCompleto, int** tabIncompleto, int dificuldade);

void copiarValoresMatriz(int** tabCompleto, int** tabIncompleto);

#endif
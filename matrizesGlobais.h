#ifndef MATRIZESGLOBAIS_H
#define MATRIZESGLOBAIS_H

extern int** sudokuCompleto;
extern int** sudokuIncompleto;

// Aloca memoria dinamicamente para as duas matrizes globais (sudokuCompleto e sudokuIncompleto), inicializa ambas com o valor 0 em cada espaco
void inicializarMatrizes();

// Desaloca a memoria alocada para as duas matrizes globais (sudokuCompleto e sudokuIncompleto)
void finalizarMatrizes();

#endif
#ifndef GERARSUDOKU_H
#define GERARSUDOKU_H

// Preenche a primeira linha da matriz sudokuCompleta ([0][i]) com valores aleatorios de 1 - 9 sem repeticao
void primeiraLinha();

// Verifica se a escolha do candidato eh valida para a posicao atual
int verificarEscolha(int num, int linha, int coluna);

// Serve para preencher o vetor c com os possiveis numeros para serem testados no sudokuBT
void gerarCandidatos(int* c, int linha, int coluna, int* numCandidatos);

// Preenche a matriz sudokuCompleta, usando backtracking, respeitando as regras do jogo sudoku
void sudokuBT(int linha, int coluna);

// Inicializa o preenchimento da matriz sudokuCompleta
void gerarSudoku();

// Gera os espaco vazios (0's) dentro da matriz sudokuIncompleta para ser usada no jogo
void gerarEspacosVazios();

// Copia os valores que estao na matriz sudokuCompleta para a sudokuIncompleta
void copiarValoresMatriz();

#endif
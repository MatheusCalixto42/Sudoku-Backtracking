#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "gerarSudoku.h"

#include "matrizesGlobais.h"
#include "variaveisGlobais.h"

void primeiraLinha() {

    int numeros[N];

    for(int i = 0; i < N; i++) {   // Preenche o vetor numeros
        numeros[i] = i + 1;
    }

    for(int i = N - 1; i > 0; i--) { // Embaralha o vetor numeros
        int j = rand() % (i + 1);
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    for(int i = 0; i < N; i++) {    // Preenche a linha da matriz com os valores "aleatorios"
        sudokuCompleto[0][i] = numeros[i];
    }

}

int verificarEscolha(int num, int linha, int coluna) {
    for (int i = 0; i < N; i++) {
        if (sudokuCompleto[linha][i] == num || sudokuCompleto[i][coluna] == num)
            return 0;
    }

    int blocoLinha = linha - linha % 3;
    int blocoColuna = coluna - coluna % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudokuCompleto[blocoLinha + i][blocoColuna + j] == num)
                return 0;

    return 1;
}

void gerarCandidatos(int* c, int linha, int coluna, int* numCandidatos) {

    int cont = 0;

    for(int num = 1; num <= N; num++) {
        if(verificarEscolha(num, linha, coluna)) {
            c[cont] = num;
            cont++;
        }
    }

    *numCandidatos = cont;
}

void sudokuBT(int linha, int coluna) {
    
    if(linha == N)   // Completou toda matriz.
        return;
    
    if(coluna == N) {   // Ir para a proxima linha quando chegar passar da ultima coluna
        sudokuBT(linha + 1, 0);
        return;
    }

    int c[N];   // Vetor de candidatos
    memset(c, 0, sizeof(c));
    int numCandidatos = 0;  // Quantidade de candidatos

    gerarCandidatos(c, linha, coluna, &numCandidatos); // Procura os numeros possiveis na posicao atual

    for(int i = 0; i < numCandidatos; i++) {    // Itera recursivamente sobre todos os candidatos validos
        sudokuCompleto[linha][coluna] = c[i];
        sudokuBT(linha, coluna + 1);

        if(sudokuCompleto[N - 1][N - 1] != 0)   // Verifica se a ultima casa (tab[8][8]) já foi preenchida
            return;
    }

    sudokuCompleto[linha][coluna] = 0; // Serve para "desfazer" a escolha caso nao seja a correta

}

void gerarSudoku() {
    primeiraLinha();

    sudokuBT(1, 0); // Como a primeira linha já foi preenchida aleatoriamente, o backtracking comeca a partir da segunda linha

    gerarEspacosVazios();   // Adiciona os espacos vazios na matriz sudokuIncompleta, que sera usada no jogo para ser completada
}

void gerarEspacosVazios() {
    
    copiarValoresMatriz();  // Copiar os dados da matriz completa para a incompleta

    int linha = 0, coluna = 0;

    for (int i = 0; i < NUM_VAZIOS; ) { // Algoritmo para escolher aleatoriamente NUM_VAZIOS espacos para zerar da matriz sudokuIncompleta
        linha = rand() % N;
        coluna = rand() % N;

        if (sudokuIncompleto[linha][coluna] != 0) {
            sudokuIncompleto[linha][coluna] = 0;
            i++;
        }
    }
}

void copiarValoresMatriz() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            sudokuIncompleto[i][j] = sudokuCompleto[i][j];
        }
    }
}

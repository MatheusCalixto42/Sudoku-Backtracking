#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "gerarSudoku.h"

void primeiraLinha(int** tab) {

    int numeros[N];

    for(int i = 0; i < N; i++) {   // Preenche o vetor numeros[]
        numeros[i] = i + 1;
    }

    srand(time(NULL));

    for(int i = N - 1; i > 0; i--) { // Embaralha o vetor numeros[]
        int j = rand() % (i + 1);
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    for(int i = 0; i < N; i++) {    // Preenche a diagonal da matriz com os valores "aleatorios"
        tab[0][i] = numeros[i];
    }

}

int verificarEscolha(int** tab, int num, int linha, int coluna) {
    for (int i = 0; i < N; i++) {
        if (tab[linha][i] == num || tab[i][coluna] == num)
            return 0;
    }

    int blocoLinha = linha - linha % 3;
    int blocoColuna = coluna - coluna % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tab[blocoLinha + i][blocoColuna + j] == num)
                return 0;

    return 1;
}

void gerarCandidatos(int** tab, int* c, int linha, int coluna, int* numCandidatos) {

    int cont = 0;

    for(int num = 1; num <= N; num++) {
        if(verificarEscolha(tab, num, linha, coluna)) {
            c[cont] = num;
            cont++;
        }
    }

    *numCandidatos = cont;
}

void sudokuBT(int** tab, int linha, int coluna) {
    
    if((linha == N - 1) && (coluna == N))   // Completou toda matriz. Ex.: 9x9 -> tab[8][9]
        return;
    
    if(coluna == N) {   // Ir para a proxima linha
        linha++;
        coluna = 0;
    }

    if (tab[linha][coluna] != 0)    // Essa condicional serve para que o backtracking analise todas os espacos da matriz, independente da quantidade de candidatos para cada vaga
        sudokuBT(tab, linha, coluna + 1);
        
    int c[N];   // Vetor de candidatos
    memset(c, 0, sizeof(c));
    int numCandidatos = 0;  // Quantidade de candidatos

    gerarCandidatos(tab, c, linha, coluna, &numCandidatos);

    for(int i = 0; i < numCandidatos; i++) {
        if(verificarEscolha(tab, c[i], linha, coluna)) {
            tab[linha][coluna] = c[i];
            sudokuBT(tab, linha, coluna + 1);
        }  
    }

}

void gerarSudoku(int** tabCompleto, int** tabIncompleto) {
    primeiraLinha(tabCompleto);
    sudokuBT(tabCompleto, 1, 0);

    gerarEspacosVazios(tabCompleto, tabIncompleto, NUM_VAZIOS);
}


void gerarEspacosVazios(int** tabCompleto, int** tabIncompleto, int dificuldade) {
    
    copiarValoresMatriz(tabCompleto, tabIncompleto);

    srand(time(NULL));

    int linha, coluna;

    for (int i = 0; i < NUM_VAZIOS; ) {
        linha = rand() % N;
        coluna = rand() % N;

        if (tabIncompleto[linha][coluna] != 0) {  // Evita repetir a mesma posição
            tabIncompleto[linha][coluna] = 0;     // Marca a posição como escolhida
            i++;
        }
    }
}

void copiarValoresMatriz(int** tabCompleto, int** tabIncompleto) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            tabIncompleto[i][j] = tabCompleto[i][j];
        }
    }
}
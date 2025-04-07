#include "jogar.h"

#include "interface.h"
#include "matrizesGlobais.h"
#include "variaveisGlobais.h"

void jogar() {

    int cont = TENTAVIVAS;

    int x = 0, y = 0;
    char c;

    while (cont && !ganhouJogo()) {

        desenhaTabuleiro(sudokuIncompleto, x, y, cont);
        
        #ifdef _WIN32
            c = getChar();

            if(c == 0 || c == -32) {    // Tecla especial (setas)
                c = getChar();
                switch (c) {
                    case 72: if (y > 0) y--; break; // seta pra cima
                    case 80: if (y < N - 1) y++; break; // Seta paa baixo
                    case 77: if (x < N - 1) x++; break; // Seta para direita
                    case 75: if (x > 0) x--; break; // Seta para esquerda
                }
            }

        #else
            c = getChar();

            if (c == '\033') { // tecla especial (ESC)
                getChar(); // [
                switch(getChar()) {
                    case 'A': if (y > 0) y--; break; // seta cima
                    case 'B': if (y < N-1) y++; break; // seta baixo
                    case 'C': if (x < N-1) x++; break; // seta direita
                    case 'D': if (x > 0) x--; break; // seta esquerda
                }
            } 
        
        #endif
        
        if (c >= '1' && c <= '9') {
            if ((c - '0') == sudokuCompleto[y][x]) {    // Caso tenha acertado o numero da casa vazia, coloca ele na matriz sudokuIncompleta
                sudokuIncompleto[y][x] = c - '0';
            } else {
                cont--; // Errou a escolha, -1 tentativa
            } 
        } else if (c == 'q' || c == 'Q') {
            break;
        }
    }

    desenhaTabuleiro(sudokuCompleto, x, y, cont);   // Mostra o tabuleiro completo (sudokuCompleto)

    if(c == 'q' || c == 'Q')
        printf("\n\nDesistiu...\n\n");
    else if(!cont)
        printf("\n\nPerdeu o jogo...\n\n");
    else
        printf("\n\nGANHOU!!!!\n\n");

    printf("\n\nEncerrado\n\n");

    c = getChar();  // "Pausa" o fim do programa
}

int ganhouJogo() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(sudokuIncompleto[i][j] == 0)
                return 0;
    
    return 1;
}


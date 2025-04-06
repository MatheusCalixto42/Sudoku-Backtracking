#include "jogar.h"

#include "interface.h"
#include "matrizesGlobais.h"
#include "variaveisGlobais.h"

void jogar() {

    int cont = TENTAVIVAS;

    int x = 0, y = 0;
    char c;

    while (cont && !ganhouJogo()) {

        desenhaTabuleiro(x, y, cont);
        c = getch();

        if (c == '\033') { // tecla especial (ESC)
            getch(); // [
            switch(getch()) {
                case 'A': if (y > 0) y--; break; // seta cima
                case 'B': if (y < N-1) y++; break; // seta baixo
                case 'C': if (x < N-1) x++; break; // seta direita
                case 'D': if (x > 0) x--; break; // seta esquerda
            }
        } else if (c >= '1' && c <= '9') {
            if ((c - '0') == sudokuCompleto[y][x]) {    // Caso tenha acertado o numero da casa vazia, coloca ele na matriz sudokuIncompleta
                sudokuIncompleto[y][x] = c - '0';
            } else {
                cont--; // Errou a escolha, -1 tentativa
            } 
        } else if (c == 'q' || c == 'Q') {
            break;
        }
    }

    if(!cont)
        printf("\n\nPerdeu o jogo...\n\n");
    else
        printf("\n\nGANHOU!!!!\n\n");

    printf("\n\nEncerrado\n\n");

}

int ganhouJogo() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(sudokuIncompleto[i][j] == 0)
                return 0;
    
    return 1;
}


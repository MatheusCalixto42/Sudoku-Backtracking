#include "jogar.h"
#include "interface.h"

void jogar(int** tabCompleto, int** tabIncompleto) {

    int cont = tentativas;

    int x = 0, y = 0;
    char c;

    while (cont) {
        desenhaTabuleiro(tabIncompleto, x, y);
        c = getch();

        if (c == '\033') { // tecla especial (ESC)
            getch(); // [
            switch(getch()) {
                case 'A': if (y > 0) y--; break; // seta cima
                case 'B': if (y < TAM-1) y++; break; // seta baixo
                case 'C': if (x < TAM-1) x++; break; // seta direita
                case 'D': if (x > 0) x--; break; // seta esquerda
            }
        } else if (c >= '1' && c <= '9') {
            if ((c - '0') == tabCompleto[y][x]) {
                tabIncompleto[y][x] = c - '0';
            } else {
                cont--;
            } 
        } else if (c == 'q' || c == 'Q') {
            break;
        }
    }

    printf("\n\nEncerrado\n\n");

}


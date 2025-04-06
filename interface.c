#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include "interface.h"

char getch() {
    struct termios oldt, newt;
    char c;
    
    tcgetattr(STDIN_FILENO, &oldt); // salva estado atual
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // modo raw
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    c = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaura modo
    return c;
}

// Limpa a tela
void limparTela() {
    printf("\033[2J\033[H");
}

void desenhaTabuleiro(int** sudoku, int sel_x, int sel_y) {
    limparTela();
    printf("\nUse as setas para mover. Digite 1-9 para inserir. Q para sair.\n\n");
    
    printf("┌───────┬───────┬───────┐\n");
    for (int i = 0; i < TAM; i++) {
        printf("│");
        for (int j = 0; j < TAM; j++) {
            if (i == sel_y && j == sel_x) {
                if (sudoku[i][j] == 0)
                    printf("[]");
                else
                    printf("[%d]", sudoku[i][j]);
            } else {
                if (sudoku[i][j] == 0)
                    printf(" .");
                else
                    printf(" %d", sudoku[i][j]);
            }

            if ((j + 1) % 3 == 0)
                printf(" │");
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i != 8)
            printf("├───────┼───────┼───────┤\n");
    }
    printf("└───────┴───────┴───────┘\n\n");

    printf("Quantidade de tentativas restantes: %d", tentativas);
}
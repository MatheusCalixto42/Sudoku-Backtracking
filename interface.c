#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h> // Biblioteca para a interface funcionar no windows
    #define CLEAR_SCREEN() system("cls")
#else
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_SCREEN() printf("\033[2J\033[H")
#endif

#include "interface.h"

#include "variaveisGlobais.h"

int NUM_VAZIOS = 20;

char getChar() {
    #ifdef _WIN32   // Se o sistema operacional for windows
        return _getch(); // Função nativa no Windows
    #else
        struct termios oldt, newt;
        char c;

        tcgetattr(STDIN_FILENO, &oldt); 
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); 
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        c = getchar(); // Lê um caractere

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return c;
    #endif
}

void limparTela() {
    CLEAR_SCREEN(); // Macro definido pra limpar a tela de acordo com o sistema operacional
}

void desenhaTabuleiro(int** tab, int sel_x, int sel_y, int tent) {
    limparTela();
    printf("\nUse as setas para mover. Digite 1-9 para inserir. Q para sair.\n\n");
    
    #ifdef _WIN32
        printf("+---------+---------+---------+\n");
        for (int i = 0; i < N; i++) {
            printf("|");
            for (int j = 0; j < N; j++) {
                if (i == sel_y && j == sel_x) {
                    if (tab[i][j] == 0)
                        printf("[]");
                    else
                        printf("[%d]", tab[i][j]);
                } else {
                    if (tab[i][j] == 0)
                        printf(" . ");
                    else
                        printf(" %d ", tab[i][j]);
                }

                if ((j + 1) % 3 == 0)
                    printf("|");
            }
            printf("\n");
            if ((i + 1) % 3 == 0 && i != 8)
                printf("+---------+---------+---------+\n");
        }
        printf("+---------+---------+---------+\n\n");
    #else
        printf("┌───────┬───────┬───────┐\n");
        for (int i = 0; i < N; i++) {
            printf("│");
            for (int j = 0; j < N; j++) {
                if (i == sel_y && j == sel_x) {
                    if (tab[i][j] == 0)
                        printf("[]");
                    else
                        printf("[%d]", tab[i][j]);
                } else {
                    if (tab[i][j] == 0)
                        printf(" .");
                    else
                        printf(" %d", tab[i][j]);
                }

                if ((j + 1) % 3 == 0)
                    printf(" │");
            }
            printf("\n");
            if ((i + 1) % 3 == 0 && i != 8)
                printf("├───────┼───────┼───────┤\n");
        }
        printf("└───────┴───────┴───────┘\n\n");
    #endif

    printf("Quantidade de tentativas restantes: %d", tent);
}

void escolherDificuldade() {
    int escolha;

    limparTela();

    printf("########## SUDOKU - BACKTRACKING ##########\n\n\n");
    printf("1 - Facil\n2 - Medio\n3 - Dificil\n\n");
    printf("Escolha uma dificuldade: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: NUM_VAZIOS = 25; break;
        case 2: NUM_VAZIOS = 40; break;
        case 3: NUM_VAZIOS = 50; break;
    }

    limparTela();

}
#ifndef INTERFACE_H
#define INTERFACE_H

// Tanto no Linux/MACOS quanto no Windows serve para captar o caracter do teclado para ser usado na interface do jogo
char getChar();

// Serve para "atualizar" o prompt, dando a ilusao de movimento
void limparTela();

// Desenha o menu de escolha de dificuldade
void escolherDificuldade();

// Desenha a matriz sudokuIncompleta para ser usada no jogo
void desenhaTabuleiro(int** tab, int sel_x, int sel_y, int tent);

#endif
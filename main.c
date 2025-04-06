#include <stdlib.h>

#include "jogar.h"
#include "interface.h"
#include "gerarSudoku.h"
#include "matrizesGlobais.h"


int main() {

    #ifdef _WIN32
        habilitarANSI();
    #endif

    srand(time(NULL));  // semente usada para calcular os numeros "aleatorios"
     
    inicializarMatrizes();

    escolherDificuldade();

    gerarSudoku();

    jogar();

    finalizarMatrizes();
    
    return 0;
}
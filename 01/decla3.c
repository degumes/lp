#include <stdio.h>

/**
* @brief Função interna que imprime "existe"
* @param e Inteiro a ser imprimido
*/
void imprimeIN(int e);

/**
* @brief Função externa que executa a interna
* @param Inteiro a ser repassado para a função interna
*/
void imprimeOUT(int e);

/**
* @brief Função principal
*/
int main(){
    int existe = 1;//experimente compilar sem esta linha

    imprimeOUT(existe);

    return 0;
}

void imprimeIN(int e){
    printf("%d\n",e);
}

void imprimeOUT(int e){
    imprimeIN(e);
}

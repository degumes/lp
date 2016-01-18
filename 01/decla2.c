#include <stdio.h>
/**
* @brief Variável global
*/
int existe;

/**
* @brief Função interna que imprime "existe"
*/
void imprimeIN(){
    printf("%d\n",existe);
}

/**
* @brief Função externa que executa a interna
*/
void imprimeOUT(){
    imprimeIN();
}

/**
* @brief Função principal
*/
int main(){
    existe = 1;//experimente compilar sem esta linha

    imprimeOUT();

    return 0;
}

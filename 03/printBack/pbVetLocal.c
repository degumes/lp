#include "stdio.h"
#include "stdlib.h"

int main(){
    //
    //
    char *frase = (char *) malloc(128*sizeof(char));
    char *palavra = (char *) malloc(16*sizeof(char));
    char letra;
    //
    //
    printf("escreva uma frase\n");
    scanf("%[^\n]s",frase);
    printf("vc escreveu:\n%s\n", frase);
    //
    //
    printf("escreva uma palavra\n");
    scanf(" %s", palavra);
    printf("vc escreveu:\n%s\n", palavra);
    //
    //
    printf("digite uma letra\n");
    scanf(" %c", &letra);
    printf("vc digitou:\n%c\n", letra);
    //
    //
    return 0;
}


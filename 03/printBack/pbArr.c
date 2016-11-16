#include "stdio.h"

char frase[128];
char palavra[16];
char letra;

int main(){
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

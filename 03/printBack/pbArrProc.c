#include "stdio.h"

char frase[128];
char palavra[16];
char letra;

void procLetra(char *l);
void procPalavra(char p[]);
void procFrase(char f[]);

int main(){
    
    procFrase( frase );
    procPalavra( palavra );
    procLetra( &letra );

    return 0;
}

void procLetra(char *l){
    printf("digite uma letra\n");
    scanf(" %c", &letra);
    printf("vc digitou:\n%c\n", letra);
    printf("\n");
}

void procPalavra(char p[]){
    printf("escreva uma palavra\n");
    scanf(" %s", p);
    printf("vc escreveu:\n%s\n", p);
    printf("\n");
}

void procFrase(char f[]){
    printf("escreva uma frase\n");
    scanf("%[^\n]s",f);
    printf("vc escreveu:\n%s\n", f);
    printf("\n");
}

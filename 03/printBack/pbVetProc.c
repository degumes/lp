#include "stdio.h"
#include "stdlib.h"

char *frase=NULL;
char *palavra=NULL;
char letra;

void procLetra(char *l);
void procPalavra(char *p);
void procFrase(char *f);

int main(){

    frase = (char *) malloc(128*sizeof(char));
    palavra = (char *) malloc(16*sizeof(char));
    
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

void procPalavra(char *p){
    printf("escreva uma palavra\n");
    scanf(" %s", p);
    printf("vc escreveu:\n%s\n", p);
    printf("\n");
}

void procFrase(char *f){
    printf("escreva uma frase\n");
    scanf("%[^\n]s",f);
    printf("vc escreveu:\n%s\n", f);
    printf("\n");
}

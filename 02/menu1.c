#include <stdio.h>
#include <stdlib.h>

int main(){
    char menuSwitch = 'm';
    char pedeTempo;
    while(menuSwitch != 'q'){
        system("clear");
        printf("tecle q para sair\n");
        printf("tecle b pra selecionar baskara\n");
        scanf(" %c", &menuSwitch);
        switch (menuSwitch) {
            case 'q':
                printf("Tchau\n");
                break;
            case 'b':
                printf("Baskara ainda não implementado\n");
                printf("qualquer letra para voltar\n");
                scanf(" %c",&pedeTempo);
                break;
        }
    }
}

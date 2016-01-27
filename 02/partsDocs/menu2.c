#include <stdio.h>
#include <stdlib.h>
#include "c.h"
//#include "bhaska.h"

int main(){
    char menuSwitch = 'm';
    while(menuSwitch != 'q'){
        system("clear");
        printf("tecle q para sair\n");
        printf("tecle b pra selecionar bhaskara\n");
        printf("tecle c pra ver C\n");
        scanf(" %c", &menuSwitch);
        switch (menuSwitch) {
            case 'q':
                printf("Tchau\n");
                break;
            case 'c':
                c();
                break;
            case 'b':
				//baska();
                break;
        }
    }
}


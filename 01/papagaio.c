#include <stdio.h>// para habilitar o printf

int main(int argc, char *argv[]){
    int i;

    if(argc == 1){
        printf("Dá o pé %s\n", argv[0]);
    }else{
        for(i=1; i<argc; i++){
            printf("%s ", argv[i]);
        }
        printf("\n");//pula linha
    }

    return 0;
}

#include <stdio.h>

int main(){
    int existe;

    void imprimeIN(){
        printf("%d\n",existe);
    }

    void imprimeOUT(){
        imprimeIN();
    }

    existe = 1;//experimente compilar sem esta linha

    imprimeOUT();

    return 0;
}

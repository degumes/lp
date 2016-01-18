#include <stdio.h>// para habilitar o printf

int main(int argc, char *argv[]){
    printf("meu nome é %s\n", argv[0]);
    return 0;
}
/*
$ gcc -Wall -g arg.c -o joaoSilva.bin
$ ./joaoSilva.bin
> meu nome é ./joaoSilva.bin
*/

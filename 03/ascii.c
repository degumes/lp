#include <stdio.h>
#include <stdlib.h>

char arr[] = "01234";

int main(){
    int i;
    long unsigned int sz;
    
    sz = sizeof(arr)/sizeof(arr[0]);
    //
    //
    printf("o tamanhdo de arr = \"%s\" é %lu\n", arr, sz);
    for(i=0; i<sz; i++){
        printf("arr[%d] = '%c'\n", i, arr[i]);
    }
    //
    //
    printf("descobrindo o código ascii\n");
     for(i=0; i<sz; i++){
        printf("arr[%d] = '%c' = %d\n", i, arr[i], (int)arr[i]);
    }
    //
    //
    int ascii[] = { 48, 49, 51, 51, 52, 0};
    printf("cobrindo o código asciis\n");
    for(i=0; i<sz; i++){
        printf("ascii[%d] = '%d' = '%c'\n", i, ascii[i], (char)ascii[i]);    
    }
    //
    //
    char arr2[] = { '0', '1', '2', '3', '4', '\0'};
    printf("exercitando outra notação\n");
    for(i=0; i<sz; i++){
        printf("'%c' = %d\n", (char)ascii[i], (int)arr2[i]);
    }
    //
    //
    if( 0  == (int)'\0' ){
        printf("\nvazio = '\\0'\n");
    }
    return 0;
}


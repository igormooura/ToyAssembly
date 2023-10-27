#include <stdio.h> 
#include <string.h>
#include "../include/decoder.h"
#include "../include/read.h"

int main(void){
    char comando[100][30];
    int x, i;

    scanf("%d\n", &x);

    for (i=0; i<x; i++){
        readCommand(comando, i);
    }
    decoder(comando);
    return 0;
}
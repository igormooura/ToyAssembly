#include <stdio.h> 
#include <string.h>
#include "../include/decoder.h"
#include "../include/read.h"

int main(void) {
    char comando[100][30];
    int i, x;

    scanf("%d", &x);
    // Consome a quebra de linha após a leitura de x
    fgetc(stdin);

    for (i = 0; i <= x; i++) {
        readCommand(comando, i);
    }

    decoder(comando, x);
    return 0;
}
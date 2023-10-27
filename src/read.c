#include <stdio.h>
#include "../include/read.h"

void readCommand(char comando[][30], int linha) {
    fgets(comando[linha], sizeof(comando[linha]), stdin);
}

#include <stdio.h>
#include <string.h>
#include "../include/read.h"

void readCommand(char comando[][30], int i) {
    fgets(comando[i], sizeof(comando[i]), stdin);
}


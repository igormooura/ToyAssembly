#include "../include/output.h"
#include <stdio.h>

void write(char reg[], int rx) {
    printf("DEBUG: write(reg[%d] = %d)\n", rx, reg[rx]);
}

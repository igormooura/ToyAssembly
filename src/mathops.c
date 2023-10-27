#include <stdio.h>
#include <string.h>
#include "../include/mathops.h"

void add(char reg[], int rx, int ry, int rz) {
    reg[rx] = reg[ry] + reg[rz];
}

void sub(char reg[], int rx, int ry, int rz) {
    reg[rx] = reg[ry] - reg[rz];
}

void divi(char reg[], int rx, int ry, int rz) {
    reg[rx] = reg[ry] / reg[rz];
}

void mul(char reg[], int rx, int ry, int rz) {
    reg[rx] = reg[ry] * reg[rz];
}

void mod(char reg[], int rx, int ry, int rz) {
    int aux = reg[ry] % reg[rz];
    reg[rx] = (aux < 0) ? (aux + reg[rz]) : aux;
}


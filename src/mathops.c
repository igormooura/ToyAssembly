#include <stdio.h>
#include <string.h>
#include "../include/mathops.h"

void add(int reg[], int rx, int ry, int rz) {
    reg[rx] = reg[ry] + reg[rz];
}

void sub(int reg[], int rx, int ry, int rz) {
    reg[rx] = reg[ry] - reg[rz];
}

void divi(int reg[], int rx, int ry, int rz) {
    reg[rx] = reg[ry] / reg[rz];
}

void mul(int reg[], int rx, int ry, int rz) {
    reg[rx] = reg[ry] * reg[rz];
}

void mod(int reg[], int rx, int ry, int rz) {
    int aux = reg[ry] % reg[rz];
    reg[rx] = (aux < 0) ? (aux + reg[rz]) : aux;
}


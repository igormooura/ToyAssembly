#include <stdio.h>
#include "../include/atribution.h"

void mov(int reg[], int rx, int ry_or_value) {
    if (rx >= 0 && rx < 32) {
        if (ry_or_value >= 0 && ry_or_value < 32) {
            reg[rx] = reg[ry_or_value];  // Move from one register to another
        }
    }
}

void movInt(int reg[], int rx, int value) {
    if (rx >= 0 && rx < 32) {
        reg[rx] = value;  // Move an integer to a register
    }
}
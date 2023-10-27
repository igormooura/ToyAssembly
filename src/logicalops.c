#include <stdio.h>
#include <stdlib.h>
#include "../include/logicalops.h"

int beq(char reg[], int rx, int ry)
{
   if (reg[rx] == reg[ry]) {
        return 1; 
    } else {
        return 0; 
    }
}

int blt(char reg[], int rx, int ry)
{
    if (reg[ry] < reg[rx]) {
        return 1; 
    } else {
        return 0; 
    }
}
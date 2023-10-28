#include <stdio.h>
#include <stdlib.h>
#include "../include/memoryops.h"

void load(int reg[], int memory[], int rx, int ry)
{
    reg[rx] = memory[ry];
}

void store(int reg[], int memory[], int rx, int ry)
{
    memory[ry] = reg[rx];
}




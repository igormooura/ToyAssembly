#include <stdio.h>
#include <string.h>
#include "../include/output.h"
#include "../include/memoryops.h"
#include "../include/mathops.h"
#include "../include/logicalops.h"
#include "../include/decoder.h"
#include "../include/atribution.h"


void decoder(char comando[][30]) {
    char reg[32]; 
    int memory[1000], rx = 0, ry = 0, rz = 0; 
    
    for (int i = 0; i < 100000; i++) {
        if (strcasecmp(comando[0], "PRINT") == 0) {
            write(reg, rx);
        } else if (strcasecmp(comando[0], "LOAD") == 0) {
            load(reg, memory, rx, ry);
        } else if (strcasecmp(comando[0], "STORE") == 0) {
            store(reg, memory, rx, ry);
        } else if (strcasecmp(comando[0], "ADD") == 0) {
            add(reg, rx, ry, rz);
        } else if (strcasecmp(comando[0], "SUB") == 0) {
            sub(reg, rx, ry, rz);
        } else if (strcasecmp(comando[0], "DIV") == 0) {
            divi(reg, rx, ry, rz);
        } else if (strcasecmp(comando[0], "MUL") == 0) {
            mul(reg, rx, ry, rz);
        } else if (strcasecmp(comando[0], "MOD") == 0) {
            mod(reg, rx, ry, rz);
        } else if (strcasecmp(comando[0], "BEQ") == 0) {
            beq(reg, rx, ry);
        } else if (strcasecmp(comando[0], "BLT") == 0) {
            blt(reg, rx, ry);
        } else if (strcasecmp(comando[0], "MOV") == 0) {
            mov(reg, rx, ry);
        } else if (strcasecmp(comando[0], "EXIT") == 0) {
            break;
        } else {
            
        }
    }
}


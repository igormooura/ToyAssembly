#include <stdio.h>
#include <string.h>
#include "../include/output.h"
#include "../include/memoryops.h"
#include "../include/mathops.h"
#include "../include/logicalops.h"
#include "../include/decoder.h"
#include "../include/atribution.h"

void decoder(char comando[][30]) {
    char reg[32] = {0};
    int memory[1000] = {0};
    int rx = 0, ry = 0, rz = 0;

    for (int i = 0; i < 100000; i++) {
        char aux[30];
        sscanf(comando[i], "%s", aux);

        if (strcasecmp(aux, "PRINT") == 0) {
            // Analisa a instrução PRINT
            sscanf(comando[i], "%s %d", aux, &rx);
            write(reg, rx);
        } else if (strcasecmp(aux, "LOAD") == 0) {
            // Analisa a instrução LOAD
            sscanf(comando[i], "%s %d %d", aux, &rx, &ry);
            load(reg, memory, rx, ry);
        } else if (strcasecmp(aux, "STORE") == 0) {
            // Analisa a instrução STORE
            sscanf(comando[i], "%s %d %d", aux, &rx, &ry);
            store(reg, memory, rx, ry);
        } else if (strcasecmp(aux, "ADD") == 0) {
            // Analisa a instrução ADD
            sscanf(comando[i], "%s %d %d %d", aux, &rx, &ry, &rz);
            add(reg, rx, ry, rz);
        } else if (strcasecmp(aux, "SUB") == 0) {
            // Analisa a instrução SUB
            sscanf(comando[i], "%s %d %d %d", aux, &rx, &ry, &rz);
            sub(reg, rx, ry, rz);
        } else if (strcasecmp(aux, "DIV") == 0) {
            // Analisa a instrução DIV
            sscanf(comando[i], "%s %d %d %d", aux, &rx, &ry, &rz);
            if (ry != 0) {  // Check if divisor is not zero
                divi(reg, rx, ry, rz);
            } 
        } else if (strcasecmp(aux, "MUL") == 0) {
            // Analisa a instrução MUL
            sscanf(comando[i], "%s %d %d %d", aux, &rx, &ry, &rz);
            mul(reg, rx, ry, rz);
        } else if (strcasecmp(aux, "MOD") == 0) {
            // Analisa a instrução MOD
            sscanf(comando[i], "%s %d %d %d", aux, &rx, &ry, &rz);
            if (ry != 0) {  // Check if divisor is not zero
                mod(reg, rx, ry, rz);
            } 
        } else if (strcasecmp(aux, "BEQ") == 0) {
            sscanf(comando[i], "%s %d %d %d", aux, &rx, &ry, &rz);
            if (beq(reg, rx, ry)) {
                jmp(reg, rz, &i);
            }
        } else if (strcasecmp(aux, "BLT") == 0) {
            sscanf(comando[i], "%s %d %d %d", aux, &rx, &ry, &rz);
            if (blt(reg, rx, ry)) {
                jmp(reg, rz, &i);
            }
        } else if (strcasecmp(aux, "MOV") == 0) {
            char src[30];
            sscanf(comando[i], "%s %s %d", aux, src, &rx);
            if (strcasecmp(src, "R") == 0) {
                int ry;
                sscanf(comando[i], "%s R%d %d", aux, &rx, &ry);
                mov(reg, rx, ry); // Move from one register to another
            } else {
                int value;
                sscanf(comando[i], "%s %d %d", aux, &value, &rx);
                movInt(reg, rx, value); // Move an integer to a register
            }
        } else if (strcasecmp(aux, "EXIT") == 0) {
            break;
        } else if (strcasecmp(aux, "JMP") == 0) {
            sscanf(comando[i], "%s %d", aux, &rx);
            jmp(reg, rx, &i);
        }
    }
}

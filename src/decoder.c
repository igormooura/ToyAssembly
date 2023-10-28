#include <stdio.h>
#include <string.h>
#include "../include/output.h"
#include "../include/memoryops.h"
#include "../include/mathops.h"
#include "../include/logicalops.h"
#include "../include/decoder.h"
#include "../include/atribution.h"

void decoder(char comando[][30], int n)
{
    int reg[32] = {0};
    int memory[1000] = {0};
    int rx = 0, ry = 0, rz = 0;
    int i = 0;

    for (int linha = 0, total_instr = 0; linha < n && total_instr < 100000; ++linha, ++total_instr)
    {
        char aux[30];
        sscanf(comando[i], "%s", aux);

        if (strcasecmp(aux, "PRINT") == 0)
        {
            sscanf(comando[i], "%s R%d", aux, &rx);
            write(reg, rx);
        }
        else if (strcasecmp(aux, "LOAD") == 0)
        {
            sscanf(comando[i], "%s R%d R%d", aux, &rx, &ry);
            load(reg, memory, rx, ry);
        }
        else if (strcasecmp(aux, "STORE") == 0)
        {
            sscanf(comando[i], "%s R%d R%d", aux, &rx, &ry);
            store(reg, memory, rx, ry);
        }
        else if (strcasecmp(aux, "ADD") == 0)
        {
            sscanf(comando[i], "%s R%d R%d R%d", aux, &rx, &ry, &rz);
            add(reg, rx, ry, rz);
        }
        else if (strcasecmp(aux, "SUB") == 0)
        {
            sscanf(comando[i], "%s R%d R%d R%d", aux, &rx, &ry, &rz);
            sub(reg, rx, ry, rz);
        }
        else if (strcasecmp(aux, "DIV") == 0)
        {
            sscanf(comando[i], "%s R%d R%d R%d", aux, &rx, &ry, &rz);
            if (ry != 0)
            { // Se, somente se, ry nao for = 0
                divi(reg, rx, ry, rz);
            }
        }
        else if (strcasecmp(aux, "MUL") == 0)
        {
            sscanf(comando[i], "%s R%d R%d R%d", aux, &rx, &ry, &rz);
            mul(reg, rx, ry, rz);
        }
        else if (strcasecmp(aux, "MOD") == 0)
        {
            sscanf(comando[i], "%s R%d R%d R%d", aux, &rx, &ry, &rz);
            mod(reg, rx, ry, rz);
            
        }
        else if (strcasecmp(aux, "BEQ") == 0)
        {
            sscanf(comando[i], "%s R%d R%d %d", aux, &rx, &ry, &rz);
            if (beq(reg, rx, ry))
            {
                jmp(reg, rz, &i);
            }
        }
        else if (strcasecmp(aux, "BLT") == 0)
        {
            sscanf(comando[i], "%s %d %d %d", aux, &rx, &ry, &rz);
            if (blt(reg, rx, ry))
            {
                jmp(reg, rz, &i); //vai "pular", rz
            }
        }
        else if (strcasecmp(aux, "MOV") == 0)
        {
            char src[30];
            sscanf(comando[i], "%s %s %d", aux, src, &rx);
            if (strcasecmp(src, "R") == 0)
            {
                sscanf(comando[i], "%s R%d %d", aux, &rx, &ry);
                mov(reg, rx, ry); // Move registro -> registro
            }
            else
            {
                int value;
                sscanf(comando[i], "%s R%d %d", aux, &rx, &value);
                movInt(reg, rx, value); // Move registro -> inteiro
            }
        }
        else if (strcasecmp(aux, "EXIT") == 0)
        {
            break;
        }
        else if (strcasecmp(aux, "JMP") == 0)
        {
            sscanf(comando[i], "%s %d", aux, &rx);
            jmp(reg, rx, &i);
        }
        total_instr++;
        i++;
    }
}
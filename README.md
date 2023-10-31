# ToyAssembly
Simulador de Assembly em C, 2° trabalho da matéria "Programação de Computadores 1", pelo professor Daniel Saad.
Feito por Igor de Oliveira Moura.

## Visão Geral

O programa suporta: 

- 32 registradores de inteiros de 32 bits (R0 a R31), que são inicializados com zero na execução do programa.
- Memória com capacidade para 1000 inteiros de 32 bits, também inicializada com zeros.
- Um conjunto de instruções que inclui operações como MOV, ADD, SUB, MUL, DIV, MOD, BEQ, BLT, JMP, LOAD, STORE e PRINT.

## Instruções Suportadas

Aqui estão as instruções suportadas pela linguagem SimpleASM:

- `MOV RX INTEIRO`: Atribui a RX o valor do INTEIRO.
- `MOV RX RY`: Atribui a RX o valor de RY.
- `ADD RX RY RZ`: Soma os valores de RY e RZ e armazena o resultado em RX.
- `SUB RX RY RZ`: Subtrai RZ de RY e armazena o resultado em RX.
- `MUL RX RY RZ`: Multiplica RY por RZ e armazena o resultado em RX.
- `DIV RX RY RZ`: Divide RY por RZ e armazena o resultado em RX. A divisão é inteira.
- `MOD RX RY RZ`: Toma o resultado de RY mod RZ e armazena o resultado em RX.
- `BEQ RX RY ENDERECO`: Desvia o fluxo do programa para ENDERECO se RX for igual a RY.
- `BLT RX RY ENDERECO`: Desvia o fluxo do programa para ENDERECO se RX for menor que RY.
- `JMP ENDERECO`: Desvia o fluxo do programa para ENDERECO.
- `LOAD RX RY`: Carrega o conteúdo da memória[RY] para o registrador RX.
- `STORE RX RY`: Armazena o conteúdo de RX na memória[RY].
- `PRINT RX`: Imprime uma linha na tela com o valor de RX.
- `EXIT`: Finaliza o programa.

## Módulos 
#### Módulo de Leitura (read)
O Módulo de Leitura é responsável por efetuar a leitura do programa de entrada, interpretando as instruções e convertendo-as para uma forma que possa ser processada pelo interpretador.

#### Módulo de Saída (output)
O Módulo de Saída é responsável por efetuar a impressão dos dados. Ele formata e exibe os resultados das operações e instruções conforme necessário.

#### Módulo de Controle (decoder)
 Ele é responsável por decodificar as instruções e coordenar a execução das operações correspondentes. Este módulo direciona o fluxo do programa com base nas instruções.

#### Módulo de Operações Aritméticas (mathops)
O Módulo de Operações Aritméticas é responsável por realizar as operações aritméticas, como adição, subtração, multiplicação e divisão, conforme definidas nas instruções.

#### Módulo de Operações Lógicas (logicalops)
O Módulo de Operações Lógicas lida com as operações lógicas, como BEQ (Branch if Equal), BLT (Branch if Less Than) e JMP (Jump).

#### Módulo de Operações em Memória (memoryops)
O Módulo de Operações em Memória trata das operações relacionadas à memória, incluindo LOAD (carregar conteúdo da memória em um registrador) e STORE (armazenar conteúdo de um registrador na memória).

#### Módulo de Atribuição (atribution)
O Módulo de Atribuição usa a função MOV para atribuir valores aos registradores, sendo eles inteiros ou sendo eles valores de outros registradores.

## Compilação e Execução
Digite na sequência
```bash
make
./ToyAssemblyIgorMoura
```




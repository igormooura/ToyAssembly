PROGRAM_NAME = operations
CC = gcc
CC_FLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
H_SOURCE = $(wildcard include/*.h)
C_SOURCE = $(wildcard src/*.c)
TARGET_FOLDER = bin
OBJ = $(patsubst src/%.c,build/%.o,$(C_SOURCE))

build: $(TARGET_FOLDER) $(OBJ)
	@ echo ' '
	@ echo 'Criando binário dos arquivos objetos'
	$(CC) $(OBJ) -o $(PROGRAM_NAME)
	@ echo ' '

$(TARGET_FOLDER):
	mkdir -p $(TARGET_FOLDER)

$(TARGET_FOLDER)/%.o: src/%.c $(H_SOURCE)
	@ echo ' '
	@ echo 'Compilando o arquivo: $<'
	$(CC) $(CC_FLAGS) -c $< -o $@
	@ echo ' '
	@ echo 'Compilação concluída: $@'
	@ echo ' '

run: build
	@ ./$(PROGRAM_NAME) < input.txt

clean:
	@ echo "Cleaning up..."
	rm -rvf $(wildcard $(TARGET_FOLDER)/*.o) $(PROGRAM_NAME)

debug: $(TARGET_FOLDER) $(OBJ)
	@ echo ' '
	@ echo 'Criando binário dos arquivos objetos em modo de depuração'
	$(CC) -g $(OBJ) -o $(PROGRAM_NAME)
	@ echo ' '

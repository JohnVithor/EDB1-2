# Makefile baseado no exemplo dado pelo Professor Silvio Costa Sampaio

# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito

# Comandos do sistema operacional
RM = rm -rf

# Compilador
CC=g++

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Define o alvo search como dependencias.
# Ao final da compilacao, remove os arquivos objeto.

all: dir search

debug: CFLAGS += -g -O0 -pg
debug: search

# Alvo (target) para a construcao do executavel geometrica
# Define os arquivos linear.o binary.o ternary.o time_tests.o main.o como dependencias
search: $(OBJ_DIR)/linear.o $(OBJ_DIR)/binary.o $(OBJ_DIR)/ternary.o $(OBJ_DIR)/time_tests.o $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel search criado em $(BIN_DIR)] +++"
	@echo "============="



# Alvo (target) para a construcao do objeto area.o
# Define os arquivos linear.cpp e linear.h como dependencias.
$(OBJ_DIR)/linear.o: $(SRC_DIR)/linear.cpp $(INC_DIR)/linear.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -o $@ $<

# Alvo (target) para a construcao do objeto area.o
# Define os arquivos binary.cpp e binary.h como dependencias.
$(OBJ_DIR)/binary.o: $(SRC_DIR)/binary.cpp $(INC_DIR)/binary.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -o $@ $<

# Alvo (target) para a construcao do objeto area.o
# Define os arquivos ternary.cpp e ternary.h como dependencias.
$(OBJ_DIR)/ternary.o: $(SRC_DIR)/ternary.cpp $(INC_DIR)/ternary.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -o $@ $<

# Alvo (target) para a construcao do objeto area.o
# Define os arquivos time_tests.cpp e time_tests.h como dependencias.
$(OBJ_DIR)/time_tests.o: $(SRC_DIR)/time_tests.cpp $(INC_DIR)/time_tests.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -o $@ $<

# Alvo (target) para a construcao do objeto area.o
# Define o arquivo main.cpp e search.h como dependencias.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -o $@ $<


# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) para a criação dos diretórios dos binários e dos objetos
# Usado antes de iniciar a compilação
dir:
	mkdir -p bin build doc
# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) gmon.out

# FIM do Makefile

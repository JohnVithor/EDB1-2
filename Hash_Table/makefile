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
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all clean distclean doxy dir valgrind_simple valgrind_full

all: dir $(BIN_DIR)/hash_table

debug: CFLAGS += -g -O0 -pg
debug: $(BIN_DIR)/hash_table

$(BIN_DIR)/hash_table: $(OBJ_DIR)/hash_table.o #$(OBJ_DIR)/driver.o
	$(CC) $(CFLAGS) -o $@ $^
	@echo ">>> [Executavel hash_table criado em $(BIN_DIR)]"

$(OBJ_DIR)/hash_table.o: $(SRC_DIR)/driver_ht.cpp $(INC_DIR)/hashtbl.hpp $(INC_DIR)/hashtbl.inl
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) para a criação dos diretórios dos binários e dos objetos
# Usado antes de iniciar a compilação
dir:
	mkdir -p bin build doc

# Alvo (target) para analisar o código em busca de vazamento de memória
valgrind_simple:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/hash_table

valgrind_full:
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes ./bin/hash_table
	
# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*

# FIM do Makefile

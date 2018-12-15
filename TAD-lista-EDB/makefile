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

all: dir List

debug: CFLAGS += -g -O0 -pg
debug: dir List

List: $(OBJ_DIR)/List.o #$(OBJ_DIR)/driver.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo ">>> [Executavel List criado em $(BIN_DIR)]"

#$(OBJ_DIR)/vector.o: $(INC_DIR)/vector.hpp $(INC_DIR)/vector.inl
#	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/List.o: $(SRC_DIR)/driver_list.cpp $(INC_DIR)/list.hpp $(INC_DIR)/iterators.inl $(INC_DIR)/list.inl 
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) para a criação dos diretórios dos binários e dos objetos
# Usado antes de iniciar a compilação
.PHONY: dir
dir:
	mkdir -p bin build doc

# Alvo (target) para analisar o código em busca de vazamento de memória
valgrind_simple:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/List

valgrind_full:
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes ./bin/List
	
# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*

# FIM do Makefile

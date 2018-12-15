# Makefile baseado no exemplo dado pelo Professor Silvio Costa Sampaio

# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito

# Comandos do sistema operacional
RM = rm -rf

# Compilador
CC=g++

# Variaveis para os subdiretorios
LIB_DIR=lib
INC_DIR=include
SRC_DIR=src
OBJ_DIR=build
BIN_DIR=bin
DOC_DIR=doc
TEST_DIR=test

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++1y -I$(INC_DIR)

.PHONY: all clean distclean doxy

all: dir $(BIN_DIR)/Dictionary

debug: CFLAGS += -g -O0 -pg
debug: dir $(BIN_DIR)/Dictionary

$(BIN_DIR)/Dictionary: $(SRC_DIR)/driver_dictionary.cpp $(INC_DIR)/dictionary.hpp $(INC_DIR)/dictionary.inl
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) $< -o $@ 
	@echo "+++ [Executavel Dictionary criado em $(BIN_DIR)] +++"
	@echo "============="

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

dir:
	mkdir -p bin build doc
	
valgrind:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Dictionary

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*

# FIM do Makefile

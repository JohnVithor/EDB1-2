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

.PHONY: all clean distclean doxy

all: dir Heap.out

debug: CFLAGS += -g -O0 -pg
debug: dir Heap.out

Heap.out: $(OBJ_DIR)/Heap.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo ">>> [Executavel Heap.out criado em $(BIN_DIR)]"

$(OBJ_DIR)/Heap.o: $(SRC_DIR)/driver_heap.cpp
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
valgrindSimple:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Heap.out

valgrindFull:
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes ./bin/Heap.out
	
# Alvo para verificar se o código está de acordo com as métricas estabelecidas
lint_complete:
	python2 cpplint.py --extensions=hpp,cpp,inl $(arg1)

lint:
	python2 cpplint.py --filter=-runtime/references,-whitespace/line_length --extensions=hpp,cpp,inl $(arg1)

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*

# FIM do Makefile

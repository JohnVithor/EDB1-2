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

INC_DIR=./include/
INC_DIR_NODE=./include/BinaryNode
INC_DIR_TREE=./include/BinaryTree
INC_DIR_AVL=./include/AVLTree
INC_DIR_SEARCH=./include/BinarySearchTree

SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

INCLUDES = $(wildcard include/*)

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++17 -I$(INC_DIR_NODE) -I$(INC_DIR_TREE) -I$(INC_DIR_AVL) -I$(INC_DIR_SEARCH)

.PHONY: all clean distclean doxy

all: dir node.out tree.out search.out avl.out

debug: CFLAGS += -g -O0 -pg
debug: dir node.out tree.out search.out avl.out

node.out: $(OBJ_DIR)/node.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo ">>> [Executavel $@ criado em $(BIN_DIR)]"

tree.out: $(OBJ_DIR)/tree.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo ">>> [Executavel $@ criado em $(BIN_DIR)]"

search.out: $(OBJ_DIR)/search.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo ">>> [Executavel $@ criado em $(BIN_DIR)]"

avl.out: $(OBJ_DIR)/avl.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo ">>> [Executavel $@ criado em $(BIN_DIR)]"

$(OBJ_DIR)/node.o: $(SRC_DIR)/driverBinaryNode.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/tree.o: $(SRC_DIR)/driverBinaryTree.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/search.o: $(SRC_DIR)/driverBinarySearchTree.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/avl.o: $(SRC_DIR)/driverAVLTree.cpp
	$(CC) -c $(CFLAGS) -o $@ $<
	
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
	valgrind -v --leak-check=full --show-reachable=yes $(arg1)

valgrind_full:
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes $(arg1)
	
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
	
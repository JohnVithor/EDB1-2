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

all: dir Sorter

debug: CFLAGS += -g -O0 -pg
debug: dir Sorter

Sorter: $(OBJ_DIR)/auxfunc.o $(OBJ_DIR)/alloc.o $(OBJ_DIR)/sorter_V.o $(OBJ_DIR)/sorter_IT.o $(OBJ_DIR)/sorter_V_C.o $(OBJ_DIR)/sorter_IT_C.o $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo ">>> [Executavel Sorter criado em $(BIN_DIR)]"

$(OBJ_DIR)/auxfunc.o: $(SRC_DIR)/auxfunc.cpp $(INC_DIR)/auxfunc.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/alloc.o: $(SRC_DIR)/alloc.cpp $(INC_DIR)/alloc.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/sorter_V.o: $(SRC_DIR)/sorter_V.cpp $(INC_DIR)/sorter_V.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/sorter_IT.o: $(SRC_DIR)/sorter_IT.cpp $(INC_DIR)/sorter_IT.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<
	
$(OBJ_DIR)/sorter_V_C.o: $(SRC_DIR)/sorter_V_C.cpp $(INC_DIR)/sorter_V_C.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/sorter_IT_C.o: $(SRC_DIR)/sorter_IT_C.cpp $(INC_DIR)/sorter_IT_C.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<
	
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<


# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) para a criação dos diretórios dos binários e dos objetos
# Usado antes de iniciar a compilação
dir:
	mkdir -p bin build doc tempos

# Alvo (target) para analisar o código em busca de vazamento de memória (modo 1)
valgrind_simple:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Sorter

# Alvo (target) para analisar o código em busca de vazamento de memória (modo 2)
valgrind_full:
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes ./bin/Sorter

# Alvo (target) usado para analise estatica do código. (modo 1)
# analisa o arquivo indicado por arg1 - modo de usar: make lint_complete arg1=_caminho-do-arquivo_
# substituir _caminho-do-arquivo_ pelo caminho do arquivo.
lint_complete:
	python2 cpplint.py --headers=hpp $(arg1)
	
# Alvo (target) usado para analise estatica do código. (modo 2)
# analisa o arquivo indicado por arg1 e filtra erros de tamanho da linha e de referencias
# - modo de usar: make lint_complete arg1=_caminho-do-arquivo_
# substituir _caminho-do-arquivo_ pelo caminho do arquivo.
lint:
	python2 cpplint.py --filter=-runtime/references,-whitespace/line_length --headers=hpp $(arg1)

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*

# FIM do Makefile

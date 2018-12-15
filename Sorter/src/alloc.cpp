/**
* @file		alloc.cpp
* @brief	Arquivo com a implementação das funções de teste de alocação
* @author	João Vítor Venceslau Coelho
* @since	30/09/2017
* @date		14/03/2018
*/

#include <iostream>
#include "alloc.hpp"

using ValueType = unsigned int;

bool test_alloc(ValueType size) {
	ValueType *vector;
	try {
		vector = new ValueType[size];
	}
	catch(std::bad_alloc& ba) {
		//std::cerr << "bad_alloc caught: " << ba.what() << size <<std::endl;
		//std::cerr << "Falha na alocação de um vetor[" << size << "]" << std::endl;
		return false;
	}
	delete[] vector;
	return true;
}

ValueType alloc_greater() {
	ValueType size = 16384u;	//	Inicia em 2^14
				//	 1073741824u //	2^30 máximo encontrado no meu computador
	while(test_alloc(size) == 0) {
		size *= 2;
	}
	return (size/2); // O size falhou no teste anterior, logo é retornado o último valor válido
}

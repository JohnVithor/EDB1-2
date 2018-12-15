/**
* @file		linear.cpp
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	15/08/2017
* @date		24/08/2017
* @sa		
*/

#include <iostream>
#include "linear.h"

int * linear_search (int * first_, int * last_, int target){
	while (first_ != last_ and * first_ != target and *first_ < target) {
		++first_;
	}
	return first_;
}

int * linear_search_sorted (int * first_, int * last_, int target){
	while (first_ != last_ and *first_ != target and *first_ < target) {
		++first_;
	}
	return (*first_ == target ) ? first_ : last_;
}

int * linear_search_recursive_internal (int * first_, int * last_, int target){
	if (*first_ == target){
		return first_;
	} else {
		return linear_search_recursive_internal(++first_, last_, target);
	}
}

int * linear_search_recursive (int * first_, int * last_, int target){
	if (target > 174634){
		std::cout << ">>> ERRO: Valor muito alto, possivel estouro de pilha. Cancelando busca...\n";
		return last_;
	}
	if (target < *first_ or target > *(last_-1)){
		return last_;
	} else {
		return linear_search_recursive_internal(first_, last_, target);
	}
}
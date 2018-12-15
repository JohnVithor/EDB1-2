/**
* @file		binary.cpp
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
#include "binary.h"

int * binary_search_recursive_internal (int *first_, int *last_, int target){
	int *meio = (int*) (first_ + (int)((last_ - first_)/2));	// Josivan

	if (target == *meio){
		return meio;

	} else if (target > *meio){
		return binary_search_recursive_internal(meio+1, last_, target);
	} else {
		return binary_search_recursive_internal(first_, meio-1, target);
	}
}

int * binary_search_recursive (int *first_, int *last_, int target){
	if (target < *first_ or target > *(last_-1)){
		return last_;
	} else {
		return binary_search_recursive_internal(first_, last_, target);
	}
	
}
int * binary_search_P(int* first_,int* last_, int target){
	if (target < *first_ or target > *(last_ - 1)){
		return last_;
	}

	int count = ((last_ - first_)/2);
	//int count = std::distance(first_, last_);
	int* M;

	while(count > 0){
		M = first_ + count/2;	// auto M(first_);  std::advance ( m , count/2);

		if (*first_ == target){
			return first_;
		} else if (*(last_-1) == target){
			return last_-1;
		}else if (*M == target){
			return M;
		} else if(*M > target){
			count = count/2;
		} else {
			first_ = ++M;
			if (count%2 == 0){
				count = count/2 - 1;
			} else {
				count = count/2;
			}
		}
	}
	return last_;
}
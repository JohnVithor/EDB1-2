/**
* @file		ternary.cpp
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	15/08/2017
* @date		24/08/2017
* @sa		
*/

#include "ternary.h"

int * ternary_search_recusirve_internal (int *primeiro, int *ultimo, int target){
	int * meio_e = (int*) (primeiro + (int)((ultimo - primeiro)/3));	// Josivan
	int * meio_d = (int*) (primeiro + (int)2*((ultimo - primeiro)/3));	// Josivan
	
	if (*meio_e == target){
		return meio_e;

	} else if (*meio_d == target){
		return meio_d;

	} else if (target < *meio_e){
		return ternary_search_recusirve_internal(primeiro, meio_e-1, target);
	} else if (target < *meio_d){
		return ternary_search_recusirve_internal(meio_e+1, meio_d-1, target);
	} else {
		return ternary_search_recusirve_internal(meio_d+1, ultimo, target);
	}
}

int * ternary_search_recusirve (int *primeiro, int *ultimo, int target){
	if (target < *primeiro or target > *(ultimo-1)){
		return ultimo;
	} else {
		return ternary_search_recusirve_internal(primeiro, ultimo, target);
	}
	
}
/*
int * ternary_search_P(int* first_,int* last_, int target){ // Não está funcionando
	if (target < *first_ or target > *(last_ - 1)){
		return last_;
	}

	int count = ((last_ - first_)/3);

	int* meio_e;
	int* meio_d;

	while(count > 0){
		meio_e = first_ + count/3;
		meio_d = first_ + 2*(count/3);

		if (*first_ == target){
			return first_;

		} else if(target < *meio_e){
			++first_;
			if (count%3 == 0){
				count = count/3;
			} else if (count%3 == 1){
				count = 
			} else {
				count = 
			}
			
		} else if (*meio_e == target){
			return meio_e;

		} else if (target < *meio_d){
			first_ = ++meio_e;
			if (count%3 == 0){
				count = count/3;
			} else if (count%3 == 1){
				count = 
			} else {
				count = 
			}

		} else if(*meio_d == target){
			return meio_d;

		} else if (target > *meio_d){
			first_ = ++meio_d;
			if (count%3 == 0){
				count = count/3;
			} else if (count%3 == 1){
				count = 
			} else {
				count = 
			}

		}
	}
	if (*first_ == target){
		return first_;
	}
	return last_;
}*/
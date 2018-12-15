/**
* @file		time_tests.h
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	24/08/2017
* @date		26/08/2017
* @sa		
*/

#ifndef TIME_TESTS_H
#define TIME_TESTS_H
#include <fstream>

void tests_rec(int* vetor, int* last_, std::ofstream &tempos);

void compute_show_time_rec(int* first_,int* last_ ,int target, std::ofstream &tempo);

#endif
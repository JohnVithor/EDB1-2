/**
* @file		main.cpp
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	15/08/2017
* @date		26/08/2017
* @sa		
*/

#include <iostream>  // cout, endl
#include <fstream>
#include <random>

#include <chrono>	 // chrono
#include <iomanip>

#include "linear.h"
#include "binary.h"
#include "ternary.h"
#include "time_tests.h"

int main(){
	std::cout << ">>> Digite a quantidade de vetores a serem analisados: ";
	int vetores;
	std::cin >> vetores;

	std::ofstream tempos_test;
	tempos_test.open ("tempos_test.csv");
	tempos_test << "tam_vet,tipo_busca,mili,nano,seg" << std::endl;

	std::ofstream tempo;
	tempo.open ("tempo.csv");
	tempo << "tam_vet,tipo_busca,alvo,mili,nano;seg" << std::endl;

	std::default_random_engine generator;
	int alvo_procurado;

	for (int i = 1; i <= vetores; ++i){
		int *vetor = new int[i+1];

		for (int j = 0; j < i; ++j){
			vetor[j] = j;
		}
		int *end = vetor + i;		
	
		tests_rec(vetor , end, tempos_test);

		std::uniform_int_distribution<int> distribution(0,i-1);
		alvo_procurado = distribution(generator);

		compute_show_time_rec(vetor, end , alvo_procurado, tempo);

		delete[] vetor;
	}

	tempos_test.close();
	tempo.close();
//----------------------------------------------------------------------------------------------//
/*
	int *test = new int[52];
	for (int j = 0; j < 52; ++j){
		test[j] = j;
	}
	int *test_end = test + 51;		

	auto start = std::chrono::steady_clock::now();

	auto result = ternary_search_recusirve( test, test_end, 24); // <--- mude a busca aki

	auto end = std::chrono::steady_clock::now();

	auto diff = end - start;

	std::cout << 52;
	std::cout << "," << "Ternary"; // E oq aparece na tela aki
	std::cout << "," << *result;

	// Milliseconds (10^-3)
	std::cout << "," << std::setprecision(9) << std::chrono::duration <double, std::milli> (diff).count();

	// Nanoseconds (10^-9)
	std::cout << "," << std::chrono::duration <double, std::nano> (diff).count();
	
	// Seconds
	auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
	std::cout << "," << diff_sec.count() << std::endl;

	delete[] test;
*/
	return 0;
}

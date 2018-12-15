/**
* @file		time_tests.cpp
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	24/08/2017
* @date		26/08/2017
* @sa		
*/

#include <iostream>  // cout, endl
#include <cassert>	 // assert()
#include <chrono>	 // chrono
#include <fstream>
#include <iomanip>

#include "linear.h"
#include "binary.h"
#include "ternary.h"

void tests_rec(int* vetor, int* last_, std::ofstream &tempos){
	int distance = std::distance(vetor, last_);

	std::cout << ">>> Linear test... " << distance << std::endl;
	auto start_l = std::chrono::steady_clock::now();

		for (int i = 0; i < distance; ++i){
			auto result = linear_search_recursive( vetor, last_, vetor[i] );
			//std::cout << ">>> " << i << std::endl;
			assert(*result == vetor[i]);
		}

	auto end_l = std::chrono::steady_clock::now();
	std::cout << ">>> Linear success...\n";

	std::cout << ">>> Binary test..." << distance << std::endl;
	auto start_b = std::chrono::steady_clock::now();

		for (int i = 0; i < distance; ++i){
			auto result = binary_search_recursive( vetor, last_, vetor[i] );
			//std::cout << ">>> " << i << std::endl;
			assert(*result == vetor[i]);
		}

	auto end_b = std::chrono::steady_clock::now();
	std::cout << ">>> Binary success...\n";

	std::cout << ">>> Ternary test..." << distance << std::endl;
	auto start_t = std::chrono::steady_clock::now();

		for (int i = 0; i < distance; ++i){
			auto result = ternary_search_recusirve( vetor, last_, vetor[i] );
			//std::cout << ">>> " << i << std::endl;
			assert(*result == vetor[i]);
		}

	auto end_t = std::chrono::steady_clock::now();
	std::cout << ">>> Ternary success...\n";

	auto diff_l = end_l - start_l;
	auto diff_b = end_b - start_b;
	auto diff_t = end_t - start_t;

//----------------------------------------------------------------------------------------//
	tempos << distance;
	tempos << "," << "Linear";

	// Milliseconds (10^-3)
	tempos << "," << std::setprecision(9) << std::chrono::duration <double, std::milli> (diff_l).count();

	// Nanoseconds (10^-9)
	tempos << "," << std::chrono::duration <double, std::nano> (diff_l).count();
	
	// Seconds
	auto diff_l_sec = std::chrono::duration_cast<std::chrono::seconds>(diff_l);
	tempos << "," << diff_l_sec.count() << std::endl;

//----------------------------------------------------------------------------------------//
	tempos << distance;
	tempos << "," << "Binary";

	// Milliseconds (10^-3)
	tempos << "," << std::setprecision(9) << std::chrono::duration <double, std::milli> (diff_b).count();

	// Nanoseconds (10^-9)
	tempos << "," << std::chrono::duration <double, std::nano> (diff_b).count();
	
	// Seconds
	auto diff_b_sec = std::chrono::duration_cast<std::chrono::seconds>(diff_b);
	tempos << "," << diff_b_sec.count() << std::endl;

//----------------------------------------------------------------------------------------//
	tempos << distance;
	tempos << "," << "Ternary";

	// Milliseconds (10^-3)
	tempos << "," << std::setprecision(9) << std::chrono::duration <double, std::milli> (diff_t).count();

	// Nanoseconds (10^-9)
	tempos << "," << std::chrono::duration <double, std::nano> (diff_t).count();
	
	// Seconds
	auto diff_t_sec = std::chrono::duration_cast<std::chrono::seconds>(diff_t);
	tempos << "," << diff_t_sec.count() << std::endl;
//----------------------------------------------------------------------------------------//
}

void compute_show_time_rec(int* first_,int* last_ ,int target, std::ofstream &tempo){
	int distance = std::distance(first_, last_);
	
	std::cout << ">>> STARTING computation that needs timing <<<\n";
	
	std::cout << ">>> Linear...\n";
	auto start_l = std::chrono::steady_clock::now();
	auto result_l = linear_search_recursive( first_, last_, target );
	auto end_l = std::chrono::steady_clock::now();
	
	std::cout << ">>> Binary...\n";
	auto start_b = std::chrono::steady_clock::now();
	auto result_b = binary_search_recursive( first_, last_, target );
	auto end_b = std::chrono::steady_clock::now();
 	
 	std::cout << ">>> Ternary...\n";
	auto start_t = std::chrono::steady_clock::now();
	auto result_t = ternary_search_recusirve( first_, last_, target );
	auto end_t = std::chrono::steady_clock::now();

	std::cout << ">>> ENDING computation that needs timing <<<\n";
 
 	auto diff_l = end_l - start_l;
	auto diff_b = end_b - start_b;
	auto diff_t = end_t - start_t;

//----------------------------------------------------------------------------------------//
	tempo << distance;
	tempo << "," << "Linear";
	tempo << "," << *result_l;

	// Milliseconds (10^-3)
	tempo << "," << std::setprecision(9) << std::chrono::duration <double, std::milli> (diff_l).count();

	// Nanoseconds (10^-9)
	tempo << "," << std::chrono::duration <double, std::nano> (diff_l).count();
	
	// Seconds
	auto diff_l_sec = std::chrono::duration_cast<std::chrono::seconds>(diff_l);
	tempo << "," << diff_l_sec.count() << std::endl;

//----------------------------------------------------------------------------------------//
	tempo << distance;
	tempo << "," << "Binary";
 	tempo << "," << *result_b;

	// Milliseconds (10^-3)
	tempo << "," << std::setprecision(9) << std::chrono::duration <double, std::milli> (diff_b).count();

	// Nanoseconds (10^-9)
	tempo << "," << std::chrono::duration <double, std::nano> (diff_b).count();
	
	// Seconds
	auto diff_b_sec = std::chrono::duration_cast<std::chrono::seconds>(diff_b);
	tempo << "," << diff_b_sec.count() << std::endl;

//----------------------------------------------------------------------------------------//
	tempo << distance;
	tempo << "," << "Ternary";
	tempo << "," << *result_t;
	// Milliseconds (10^-3)
	tempo << "," << std::setprecision(9) << std::chrono::duration <double, std::milli> (diff_t).count();

	// Nanoseconds (10^-9)
	tempo << "," << std::chrono::duration <double, std::nano> (diff_t).count();
	
	// Seconds
	auto diff_t_sec = std::chrono::duration_cast<std::chrono::seconds>(diff_t);
	tempo << "," << diff_t_sec.count() << std::endl;
//----------------------------------------------------------------------------------------//
}

// Copyright 2018 JV

/**
 * @file auxfunc.cpp
 * @brief      Arquivo com a implementação das funções auxiliares,
 *             principalmente as referentes a análise empírica
 * @author     João Vítor Venceslau Coelho
 * @since      14/09/2017
 * @date       23/03/2018
 */

#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <random>
#include <functional>
#include <algorithm>
#include <vector>

#include "sorter_V.hpp"
#include "sorter_IT.hpp"
#include "auxfunc.hpp"

#define NUMBER_OF_TESTS 50;
// #define NUMBER_OF_FUNCTIONS 7;  // Por algum motivo que eu não entendi, não posso utilizar essa macro em algumas comparações
const int NUMBER_OF_FUNCTIONS = 7;

using ValueType = unsigned int;

using UnsignedVector = std::vector<ValueType>;
using UnsignedIterator = std::vector<ValueType>::iterator;

using OrdFuncVector = void (*) (UnsignedVector &, ValueType, ValueType);
using OrdFuncIterator = void (*) (UnsignedIterator, UnsignedIterator);
using AnalyzeFuncType = void (*) (UnsignedVector &, UnsignedVector &, std::ofstream &, ValueType, ValueType, int);

double test_time_vector(UnsignedVector &target,
                        ValueType left,
                        ValueType right,
                        OrdFuncVector srt) {
    auto start = std::chrono::steady_clock::now();
    srt(target, left, right);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    return std::chrono::duration<double, std::milli>(diff).count();
}

double test_time_iterator(UnsignedIterator first, UnsignedIterator last, OrdFuncIterator srt) {
    auto start = std::chrono::steady_clock::now();
    srt(first, last);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    return std::chrono::duration<double, std::milli>(diff).count();
}

void run_analyze_vector(UnsignedVector &target,
                        UnsignedVector &original,
                        std::ofstream &archive,
                        ValueType amount_values,
                        ValueType amount_tests,
                        int func_id) {
    OrdFuncVector ord_func_vector[] = {
        insertion_sort_vector,  // 0
        selection_sort_vector,  // 1
        bubble_sort_vector,     // 2
        merge_sort_vector,      // 3
        quick_sort_vector,      // 4
        shell_sort_vector,      // 5
        radix_sort_vector       // 6
    };
    double media = 0;
    for (ValueType j = 1; j <= amount_tests; ++j) {
        media += ((test_time_vector(target, 0, amount_values, (ord_func_vector[func_id])) - media) / j);
        target = original;
    }
    archive << "," << std::fixed << std::setprecision(9) << media;
}

void run_analyze_iterator(UnsignedVector &target,
                          UnsignedVector &original,
                          std::ofstream &archive,
                          ValueType amount_values,
                          ValueType amount_tests,
                          int func_id) {
    OrdFuncIterator ord_func_iterator[] = {
        insertion_sort_iterator,    // 0
        selection_sort_iterator,    // 1
        bubble_sort_iterator,       // 2
        merge_sort_iterator,        // 3
        quick_sort_iterator,        // 4
        shell_sort_iterator,        // 5
        radix_sort_iterator         // 6
    };
    double media = 0;
    for (ValueType j = 1; j <= amount_tests; ++j) {
        media += ((test_time_iterator(target.begin(), target.begin() + amount_values, (ord_func_iterator[func_id])) - media) / j);
        target = original;
    }
    archive << "," << std::fixed << std::setprecision(9) << media;
}

void non_decreasing_fill(UnsignedVector &target) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int>distribution(0, 1);
    ValueType i = 1;
    for (auto it = target.begin(); it != target.end(); ++it) {
        *it = (distribution(generator) == 0) ? i : ++i;
    }
}

void non_increasing_fill(UnsignedVector &target, ValueType initial_value) {
    std::random_device rnd_device;
    std::default_random_engine generator(rnd_device());
    std::uniform_int_distribution<int>distribution(0, 1);
    ValueType i = initial_value;
    for (auto it = target.begin(); it != target.end(); ++it) {
        *it = (distribution(generator) == 0) ? i : --i;
    }
}

void decreasing_fill(UnsignedVector &target, ValueType initial_value) {
    ValueType i = initial_value;
    for (auto it = target.begin(); it != target.end(); ++it) {
        *it = --i;
    }
}

void random_fill(UnsignedVector &target, ValueType max_value) {
    std::random_device rnd_device;
    std::default_random_engine generator(rnd_device());
    std::uniform_int_distribution<int>distribution(1, max_value);
    auto gen = std::bind(distribution, generator);
    std::generate(target.begin(), target.end(), gen);
}

void non_decreasing_analyze(UnsignedVector &target,
                            UnsignedVector &original,
                            ValueType amount_values,
                            ValueType amount_tests,
                            AnalyzeFuncType function,
                            std::ofstream &archive) {
    std::cout << "\nO Vetor será preenchido de forma não decrescente, por favor aguarde ..." << std::endl;
    non_decreasing_fill(original);
    std::cout << "Vetor preenchido de forma não decrescente, por favor aguarde enquanto esta organização é salva..." << std::endl;
    target = original;
    std::cout << "Vetor salvo, iniciando análises para valores não decrescentes...\n" << std::endl;

    ValueType range = amount_values / NUMBER_OF_TESTS;
    for (ValueType i = range; i <= amount_values; i += range) {
        std::cout << "== Analisando para " << i << " elementos ==" << std::endl;
        archive << i;
        for (int f = 0; f < NUMBER_OF_FUNCTIONS; ++f) {
            function(target, original, archive, i, amount_tests, f);
        }
        archive << std::endl;
    }
    archive.close();
}

void non_increasing_analyze(UnsignedVector &target,
                            UnsignedVector &original,
                            ValueType amount_values,
                            ValueType amount_tests,
                            AnalyzeFuncType function,
                            std::ofstream &archive) {
    std::cout << "\nO Vetor será preenchido de forma não crescente, por favor aguarde ..." << std::endl;
    non_increasing_fill(original, amount_values);
    std::cout << "Vetor preenchido de forma não crescente, por favor aguarde enquanto esta organização é salva..." << std::endl;
    target = original;
    std::cout << "Vetor salvo, iniciando análises para valores não crescentes...\n" << std::endl;

    ValueType range = amount_values / NUMBER_OF_TESTS;
    for (ValueType i = range; i <= amount_values; i += range) {
        std::cout << "== Analisando para " << i << " elementos ==" << std::endl;
        archive << i;
        for (int f = 0; f < NUMBER_OF_FUNCTIONS; ++f) {
            function(target, original, archive, i, amount_tests, f);
        }
        archive << std::endl;
    }
    archive.close();
}

void random_analyze(UnsignedVector &target,
                    UnsignedVector &original,
                    ValueType amount_values,
                    ValueType amount_tests,
                    AnalyzeFuncType function,
                    std::ofstream &archive) {
    std::cout << "\nO Vetor será preenchido aleatoriamente, por favor aguarde ..." << std::endl;
    random_fill(original, amount_values);
    std::cout << "Vetor preenchido aleatoriamente, por favor aguarde enquanto esta organização é salva..." << std::endl;
    target = original;
    std::cout << "Vetor salvo, iniciando análises para valores aleatórios...\n" << std::endl;

    ValueType range = amount_values / NUMBER_OF_TESTS;
    for (ValueType i = range; i <= amount_values; i += range) {
        std::cout << "== Analisando para " << i << " elementos ==" << std::endl;
        archive << i;
        for (int f = 0; f < NUMBER_OF_FUNCTIONS; ++f) {
            function(target, original, archive, i, amount_tests, f);
        }
        archive << std::endl;
    }
    archive.close();
}

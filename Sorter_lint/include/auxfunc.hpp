// Copyright 2018 JV

/**
 * @file auxfunc.hpp
 * @brief      Arquivo com a assinatura das funções auxiliares, principalmente
 *             as referentes à análise empírica e seus comentários doxy
 *
 * @author     João Vítor Venceslau Coelho
 * @since      06/10/2017
 * @date       23/03/2018
 */
#ifndef INCLUDE_AUXFUNC_HPP_
#define INCLUDE_AUXFUNC_HPP_

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>

using ValueType = unsigned int;

using UnsignedVector = std::vector<ValueType>;
using UnsignedIterator = std::vector<ValueType>::iterator;

using OrdFuncVector = void (*) (UnsignedVector &, ValueType, ValueType);
using OrdFuncIterator = void (*) (UnsignedIterator, UnsignedIterator);
using AnalyzeFuncType = void (*) (UnsignedVector &, UnsignedVector &, std::ofstream &, ValueType, ValueType, int);

/**
 * @brief      Imprime os elementos de um intervalo
 *
 * @param      first   Inicio do intervalo a ser impresso a tela
 * @param      last    Final do intervalo a ser impresso a tela
 *
 * @tparam     Pointer  Ponteiro ou Iterador, tipo que contenha endereço e possa
 *                      ser utilizado no std::copy
 */
template<typename Pointer>
void print_vector(Pointer first, Pointer last) {
    std::cout << ">>> Vetor: [ ";
    std::copy(first, last, std::ostream_iterator<decltype(*first)>(std::cout, " "));
    std::cout << "]";
}

/**
 * @brief      Realiza a cronometragem do tempo que uma função leva para
 *             terminar
 *
 * @param      target  Vector com os elementos a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      srt     Função a ser utilizada na ordenação
 *
 * @return     Tempo que a função levou para realizar a ordenação
 */
double test_time_vector(UnsignedVector &target,
                        ValueType left,
                        ValueType right,
                        OrdFuncVector srt);

/**
 * @brief      Realiza a cronometragem do tempo que uma função leva para
 *             terminar
 *
 * @param      first  Iterador para o inicio do intervalo a ser ordenado
 * @param      last   Iterador para o final do intervalo a ser ordenado
 * @param      srt     Função a ser utilizada na ordenação
 *
 * @return     Tempo que a função levou para realizar a ordenação
 */
double test_time_iterator(UnsignedIterator first, UnsignedIterator last, OrdFuncIterator srt);

/**
 * @brief      Calcula a média do tempo que uma função demora para terminar e a
 *             salva em um arquivo
 *
 * @param      target         Vector a ser utilizado na análise
 * @param      original       Vector de backup da organização dos elementos
 * @param      archive        Arquivo onde os tempos serão armazenados
 * @param      amount_values  Quantidade de elementos a serem ordenados
 * @param      amount_tests   Quantidade de testes realizados com essa
 *                            quantidade de elementos e função
 * @param      func_id        Qual função será analisada
 */
void run_analyze_vector(UnsignedVector &target,
                        UnsignedVector &original,
                        std::ofstream &archive,
                        ValueType amount_values,
                        ValueType amount_tests,
                        int func_id);

/**
 * @brief      Calcula a média do tempo que uma função demora para terminar e a
 *             salva em um arquivo
 *
 * @param      target         Vector a ser utilizado na análise
 * @param      original       Vector de backup da organização dos elementos
 * @param      archive        Arquivo onde os tempos serão armazenados
 * @param      amount_values  Quantidade de elementos a serem ordenados
 * @param      amount_tests   Quantidade de testes realizados com essa
 *                            quantidade de elementos e função
 * @param      func_id        Qual função será analisada
 */
void run_analyze_iterator(UnsignedVector &target,
                          UnsignedVector &original,
                          std::ofstream &archive,
                          ValueType amount_values,
                          ValueType amount_tests,
                          int func_id);

/**
 * @brief      Preenche um vector com elementos em ordem não decrescente
 *
 * @param      target  Vector a ser preenchido
 */
void non_decreasing_fill(UnsignedVector &target);

/**
 * @brief      Preenche um vector com elementos em ordem não crescente
 *
 * @param      target         Vector a ser preenchido
 * @param      initial_value  Valor inicial dos elementos a serem gerados
 */
void non_increasing_fill(UnsignedVector &target, ValueType initial_value);

/**
 * @brief      Preenche um vector com elementos em ordem decrescente
 * @details    Utilizada apenas no modo de testes ('-t')
 *
 * @param      target         Vector a ser preenchido
 * @param      initial_value  Valor inicial dos elementos a serem gerados
 */
void decreasing_fill(UnsignedVector &target, ValueType initial_value);

/**
 * @brief      Preenche um vector com elementos em ordem aleatória
 *
 * @param      target     Vector a ser preenchido
 * @param      max_value  Valor máximo dos elementos a serem gerados
 */
void random_fill(UnsignedVector &target, ValueType max_value);

/**
 * @brief      Realiza a cronometragem das funções de ordenação em vários
 *             intervalos com um vector em ordem não decrescente
 *
 * @param      target         Vector a ser utilizado na análise
 * @param      original       Vector de backup da organização dos elementos
 * @param      amount_values  Quantidade de elementos a serem testados
 * @param      amount_tests   Quantidade de testes realizados com essa
 *                            quantidade de elementos e função
 * @param      analyze        Função a ser utilizada na análise
 * @param      archive        Arquivo onde os tempos serão armazenados
 */
void non_decreasing_analyze(UnsignedVector &target,
                            UnsignedVector &original,
                            ValueType amount_values,
                            ValueType amount_tests,
                            AnalyzeFuncType function,
                            std::ofstream &archive);

/**
 * @brief      Realiza a cronometragem das funções de ordenação em vários
 *             intervalos com um vector em ordem não crescente
 *
 * @param      target         Vector a ser utilizado na análise
 * @param      original       Vector de backup da organização dos elementos
 * @param      amount_values  Quantidade de elementos a serem testados
 * @param      amount_tests   Quantidade de testes realizados com essa
 *                            quantidade de elementos e função
 * @param      analyze        Função a ser utilizada na análise
 * @param      archive        Arquivo onde os tempos serão armazenados
 */
void non_increasing_analyze(UnsignedVector &target,
                            UnsignedVector &original,
                            ValueType amount_values,
                            ValueType amount_tests,
                            AnalyzeFuncType function,
                            std::ofstream &archive);

/**
 * @brief      Realiza a cronometragem das funções de ordenação em vários
 *             intervalos com um vector em ordem aleatória
 *
 * @param      target         Vector a ser utilizado na análise
 * @param      original       Vector de backup da organização dos elementos
 * @param      amount_values  Quantidade de elementos a serem testados
 * @param      amount_tests   Quantidade de testes realizados com essa
 *                            quantidade de elementos e função
 * @param      function       Função a ser utilizada na análise
 * @param      archive        Arquivo onde os tempos serão armazenados
 */
void random_analyze(UnsignedVector &target,
                    UnsignedVector &original,
                    ValueType amount_values,
                    ValueType amount_tests,
                    AnalyzeFuncType function,
                    std::ofstream &archive);

#endif  // INCLUDE_AUXFUNC_HPP_

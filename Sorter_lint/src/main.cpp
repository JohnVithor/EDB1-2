// Copyright 2018 JV

/**
 * @file main.cpp
 * @brief      Arquivo com a Função Principal
 * @author     João Vítor Venceslau Coelho
 * @since      09/09/2017
 * @date       23/03/2018
 */

#include <getopt.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "auxfunc.hpp"
#include "alloc.hpp"
#include "sorter_V.hpp"
#include "sorter_IT.hpp"
#include "sorter_V_C.hpp"
#include "sorter_IT_C.hpp"

using ValueType = unsigned int;

using UnsignedVector = std::vector<ValueType>;
using UnsignedIterator = std::vector<ValueType>::iterator;

using OrdFuncVector = void (*) (UnsignedVector &, ValueType, ValueType);
using OrdFuncIterator = void (*) (UnsignedIterator, UnsignedIterator);
using OrdFuncVectorSteps = void (*) (UnsignedVector &, ValueType, ValueType, ValueType &);
using OrdFuncIteratorSteps = void (*) (UnsignedIterator, UnsignedIterator, ValueType &);

/**
* @brief    Funcao principal
* @details  Identifica qual o modo utilizado -a ou -t e quais seus parametros
* @param    argc Numero de argumentos fornecidos via linha de comando
* @param    argv Argumentos fornecidos via linha de comando
*/
int main(int argc, char **argv) {
    int a_flag = 0, v_flag = 0, i_flag = 0, t_flag = 0;
    int func = -1;
    ValueType range = 100;
    ValueType amount_tests = 10;
    int c;
    char *aux;
    opterr = 0;
    while ((c = getopt(argc, argv, "avictf:q:r:")) != -1) {
        switch (c) {
            case 'a':
                if (t_flag == 1) {
                    std::cerr <<  "Erro: Não é permitido o uso de '-a' e '-t' no mesmo comando\n";
                    return 1;
                } else {
                    a_flag = 1;
                }
                break;
            case 't':
                if (a_flag == 1) {
                    std::cerr <<  "Erro: Não é permitido o uso de '-a' e '-t' no mesmo comando\n";
                    return 1;
                } else {
                    t_flag = 1;
                }
                break;
            case 'v':
                if (i_flag == 1) {
                    std::cerr << "Erro: Não é permitido o uso de '-v' e '-i' no mesmo comando\n";
                    return 1;
                } else {
                    v_flag = 1;
                }
                break;
            case 'i':
                if (v_flag == 1) {
                    std::cerr << "Erro: Não é permitido o uso de '-v' e '-i' no mesmo comando\n";
                    return 1;
                } else {
                    i_flag = 1;
                }
                break;
            case 'f':
                if (a_flag == 1) {
                    std::cerr << "Erro: Não é permitido o uso de '-a' e '-f' no mesmo comando\n";
                    return 1;
                } else {
                    func = strtol(optarg, &aux, 10);
                    if (func < 0 || func > 6) {
                        std::cerr << "Erro: Número de função inválido, por favor indique um número entre 0 e 6\n";
                        return 1;
                    }
                }
                break;
            case 'q':
                if (t_flag == 1) {
                    std::cerr << "Erro: Não é permitido o uso de '-t' e '-q' no mesmo comando\n";
                    return 1;
                } else {
                    amount_tests = strtol(optarg, &aux, 10);
                    if (amount_tests <= 0 || amount_tests >= 10000) {
                        std::cerr << "Erro: Não é permitido usar uma quantidade nula/negativa ou acima de 10.000\n";
                        return 1;
                    }
                }
                    break;
            case 'r':
                    range = strtoul(optarg, &aux, 10);
                    if (range < 50 || range >= 1000000000) {
                        std::cerr << "Erro: Range inválido, por favor escolha um número range válido (50 <= range <= 1.000.000.000)\n";
                        return 1;
                    } else if (range == 0) {
                        range = alloc_greater()/2;
//  Como é mantida uma cópia da organização do vetor é necessário dividir o valor por 2
                    }
                    break;
            case '?':
                if (optopt == 'f' || optopt == 'q' || optopt == 'r') {
                    std::cerr << "Erro: '-" << char(optopt) << "' necessita de um argumento.\n";
                    return 1;
                } else if (isprint(optopt)) {
                    std::cerr << "Erro: '-" << char(optopt) << "' inválido.\n";
                    return 1;
                } else {
                    std::cerr << "Erro: '\\x" << optopt << "' caractere inválido\n";
                    return 1;
                }
            default:
                return 1;
        }
    }
    if ( (a_flag == 0 && func == -1) || (v_flag == 0 && i_flag == 0) ) {
        std::cout << "\t--Modo de usar--" << std::endl
                  << "'-a' - indica o modo de Análise Empírica" << std::endl
                  << "'-t' - indica o modo de Teste" << std::endl
                  << "'-v' - indica a utilização das funções com Vector por referência" << std::endl
                  << "'-i' - indica a utilização das funções com Iteradores" << std::endl
                  << "'-r (quantidade)' - indica o tamanho do range a ser utilizado (quantidade de elementos) " <<
                                                "('0' indica a maior potencia de 2 que o computador permitir)"  << std::endl
                  << "'-q (quantidade)' - indica a quantidade de testes realizados em cada análise (exclusivo do modo de Análise Empírica)" << std::endl
                  << "'-f (número da função)' - indica qual função deve ser testada (exclusivo do modo de teste)" << std::endl
                  << std::endl
                  << "--Números de cada função--" << std::endl
                  << "0 - Insertion sort" << std::endl
                  << "1 - Selection sort" << std::endl
                  << "2 - Bubble sort" << std::endl
                  << "3 - Merge sort" << std::endl
                  << "4 - Quick sort" << std::endl
                  << "5 - Shell sort" << std::endl
                  << "6 - Radix sort" << std::endl;
        return 1;
    }
    std::cout << ">>> Será alocado um vector com " << range << " Por favor aguarde..." << std::endl << std::endl;
    UnsignedVector original(range);

    if (a_flag == 1) {
        UnsignedVector source(original);
        std::string csv_colluns = "tam_vet,Insertion,Selection,Bubble,Merge,Quick,Shell,Radix";

        std::cout << "\t\t== Utilizando o modo de Análise Empírica ==" << std::endl << std::endl;
        if (v_flag == 1) {
            std::cout << "Utilizando as funções com Vector por Referência" << std::endl;
            std::cout << "Utilizando a seguinte quantidade de testes por função e quantidade de elementos: "
                      <<  amount_tests << std::endl;

//                                  Analises com Vector por referência
//                      Vector organizado com elementos em ordem não decrescente

            std::ofstream non_decreasing_vectors_time;
            non_decreasing_vectors_time.open("tempos/tempo_V_ND.csv");
            if (non_decreasing_vectors_time.bad()) {
                std::cerr << "O arquivo não foi aberto" << std::endl;
                std::exit(1);
            }
            non_decreasing_vectors_time << csv_colluns << std::endl;
            non_decreasing_analyze(source, original, range, amount_tests, run_analyze_vector, non_decreasing_vectors_time);

//                      Vector organizado com elementos em ordem não crescente

            std::ofstream non_increasing_vectors_time;
            non_increasing_vectors_time.open("tempos/tempo_V_NC.csv");
            if (non_increasing_vectors_time.bad()) {
                std::cerr << "O arquivo não foi aberto" << std::endl;
                std::exit(1);
            }
            non_increasing_vectors_time << csv_colluns << std::endl;
            non_increasing_analyze(source, original, range, amount_tests, run_analyze_vector, non_increasing_vectors_time);

//                      Vector organizado com elementos em ordem aleatória

            std::ofstream random_vectors_time;
            random_vectors_time.open("tempos/tempo_V_A.csv");
            if (random_vectors_time.bad()) {
                std::cerr << "O arquivo não foi aberto" << std::endl;
                std::exit(1);
            }
            random_vectors_time << csv_colluns << std::endl;
            random_analyze(source, original, range, amount_tests, run_analyze_vector, random_vectors_time);
        } else if (i_flag == 1) {
            std::cout << "Utilizando as funções com Iteradores" << std::endl;
            std::cout << "Utilizando a seguinte quantidade de testes por função e quantidade de elementos: "
                      <<  amount_tests << std::endl;

//                                          Analises com Iteradores
//                      Vector organizado com elementos em ordem não decrescente

            std::ofstream non_decreasing_iterators_time;
            non_decreasing_iterators_time.open("tempos/tempo_ND.csv");
            if (non_decreasing_iterators_time.bad()) {
                std::cerr << "O arquivo não foi aberto" << std::endl;
                std::exit(1);
            }
            non_decreasing_iterators_time << csv_colluns << std::endl;
            non_decreasing_analyze(source, original, range, amount_tests, run_analyze_iterator, non_decreasing_iterators_time);

//                      Vector organizado com elementos em ordem não crescente

            std::ofstream non_increasing_iterators_time;
            non_increasing_iterators_time.open("tempos/tempo_NC.csv");
            if (non_increasing_iterators_time.bad()) {
                std::cerr << "O arquivo não foi aberto" << std::endl;
                std::exit(1);
            }
            non_increasing_iterators_time << csv_colluns << std::endl;
            non_increasing_analyze(source, original, range, amount_tests, run_analyze_iterator, non_increasing_iterators_time);

//                      Vector organizado com elementos em ordem aleatória

            std::ofstream random_iterators_time;
            random_iterators_time.open("tempos/tempo_A.csv");
            if (random_iterators_time.bad()) {
                std::cerr << "O arquivo não foi aberto" << std::endl;
                std::exit(1);
            }
            random_iterators_time << csv_colluns << std::endl;
            random_analyze(source, original, range, amount_tests, run_analyze_iterator, random_iterators_time);
        }

        std::cout << std::endl << "\t\t== Fim dos testes ==" << std::endl;
        std::cout << "Os tempos de cada função dos testes foram salvos no diretório tempos." << std::endl;
    } else if (t_flag == 1) {
        std::string func_names[] = { "Insertion sort",
                                     "Selection sort",
                                     "Bubble sort",
                                     "Merge sort",
                                     "Quick sort",
                                     "Shell sort",
                                     "Radix sort" };

        std::cout << "\t\t== Utilizando o modo de Testes ==" << std::endl << std::endl;
        if (v_flag == 1) {
            // array com as possíveis funções a serem testadas
            OrdFuncVector ord_func_vectors[] = {insertion_sort_vector,
                                                    selection_sort_vector,
                                                    bubble_sort_vector,
                                                    merge_sort_vector,
                                                    quick_sort_vector,
                                                    shell_sort_vector,
                                                    radix_sort_vector };

            // array com as possíveis funções a serem testadas
            OrdFuncVectorSteps ord_func_vectors_steps[] = { insertion_sort_vector_steps,
                                                                selection_sort_vector_steps,
                                                                bubble_sort_vector_steps,
                                                                merge_sort_vector_steps,
                                                                quick_sort_vector_steps,
                                                                shell_sort_vector_steps,
                                                                radix_sort_vector_steps };

            std::cout << "Testando a função " << func_names[func] << " com Vector por Referência" << std::endl;
            decreasing_fill(original, range);

            std::cout << "Antes da ordenação" << std::endl;
            print_vector(original.begin(), original.begin() + 10);
            std::cout << std::endl;
            print_vector(original.end() - 10, original.end());
            std::cout << std::endl;

            // Calculo o tempo gasto para ordenar
            double time = test_time_vector(original, 0, range, (ord_func_vectors[func]));

            // Volto o vector para sua organização inicial
            decreasing_fill(original, range);

            // Calculo o numero de 'passos' realizados
            ValueType steps = 0;
            ord_func_vectors_steps[func](original, 0, range, steps);

            std::cout << "Após da ordenação" << std::endl;
            print_vector(original.begin(), original.begin() + 10);
            std::cout << std::endl;
            print_vector(original.end() - 10, original.end());

            std::cout << std::endl << std::endl << "Tempo de execução: " << time << std::endl;
            std::cout << "O número de passos realizados : " << steps << std::endl;
        }
        if (i_flag == 1) {
            // array com as possíveis funções a serem testadas
            OrdFuncIterator ord_func_iterators[] = { insertion_sort_iterator,
                                                     selection_sort_iterator,
                                                     bubble_sort_iterator,
                                                     merge_sort_iterator,
                                                     quick_sort_iterator,
                                                     shell_sort_iterator,
                                                     radix_sort_iterator };

            // array com as possíveis funções a serem testadas
            OrdFuncIteratorSteps ord_func_iterators_steps[] = { insertion_sort_iterator_steps,
                                                                selection_sort_iterator_steps,
                                                                bubble_sort_iterator_steps,
                                                                merge_sort_iterator_steps,
                                                                quick_sort_iterator_steps,
                                                                shell_sort_iterator_steps,
                                                                radix_sort_iterator_steps };

            std::cout << "Testando a função " << func_names[func] << " com Iteradores" << std::endl;
            decreasing_fill(original, range);

            std::cout << "Antes da ordenação" << std::endl;

            print_vector(original.begin(), original.begin() + 10);
            std::cout << std::endl;
            print_vector(original.end() - 10, original.end());
            std::cout << std::endl;

            // Calculo o tempo gasto para ordenar
            double time = test_time_iterator(original.begin(), original.end(), (ord_func_iterators[func]));

            // Volto o vector para sua organização inicial
            decreasing_fill(original, range);

            // Calculo o numero de 'passos' realizados
            ValueType steps = 0;
            ord_func_iterators_steps[func](original.begin(), original.end(), steps);

            std::cout << "Após a ordenação" << std::endl;
            print_vector(original.begin(), original.begin() + 10);
            std::cout << std::endl;
            print_vector(original.end() - 10, original.end());

            std::cout << std::endl << std::endl << "Tempo de execução: " << time << std::endl;
            std::cout << "O número de passos realizados : " << steps << std::endl;
        }
    }
    return 0;
}

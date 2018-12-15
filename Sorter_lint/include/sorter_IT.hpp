// Copyright 2018 JV

/**
 * @file sorter_IT.hpp
 * @brief      Arquivo com a assinatura das funções de ordenação (Iteradores) e
 *             seus comentários doxy
 *
 * @author     João Vítor Venceslau Coelho
 * @since      23/09/2017
 * @date       23/03/2018
 */

#ifndef INCLUDE_SORTER_IT_HPP_
#define INCLUDE_SORTER_IT_HPP_

#include <vector>

using ValueType = unsigned int;
using UnsignedIterator = std::vector<ValueType>::iterator;

/**
 * @brief      Percorre o intervalo e a cada elemento analisado, o ordena em
 *             relação aos elementos já analisados
 *
 * @param      first  Iterador para o inicio do intervalo a ser ordenado
 * @param      last   Iterador para o fim do intervalo a ser ordenado
 */
void insertion_sort_iterator(UnsignedIterator first, UnsignedIterator last);

/**
 * @brief      Percorre o intervalo em busca do menor elemento e o troca com o
 *             elemento do inicio do intervalo ainda não ordenado
 *
 * @param      first  Iterador para o inicio do intervalo a ser ordenado
 * @param      last   Iterador para o fim do intervalo a ser ordenado
 */
void selection_sort_iterator(UnsignedIterator first, UnsignedIterator last);

/**
 * @brief      Percorre o vetor trocando os elementos maiores com os menores, de
 *             modo que a cada iteração o maior elemento fique no fim do
 *             intervalo não ordenado
 *
 * @param      first  Iterador para o inicio do intervalo a ser ordenado
 * @param      last   Iterador para o fim do intervalo a ser ordenado
 */
void bubble_sort_iterator(UnsignedIterator first, UnsignedIterator last);

/**
 * @brief      Particiona o intervalo em duas partes, menores que o pivô e
 *             maiores ou iguais ao pivô, o último elemento é escolhido como
 *             pivô
 *
 * @param      first  Iterador para o inicio do intervalo a ser "pivotado"
 * @param      last   Iterador para o fim do intervalo a ser "pivotado"
 *
 * @return     Iterador para o elemento "pivô" após a "pivotagem"
 */
UnsignedIterator partition_iterator(UnsignedIterator first, UnsignedIterator last);

/**
 * @brief      Após particionar o intervalo em dois menores, chama o quick_sort_iterator
 *             nas duas partições
 *
 * @param      first  Iterador para o inicio do intervalo a ser ordenado
 * @param      last   Iterador para o fim do intervalo a ser ordenado
 */
void quick_sort_iterator(UnsignedIterator first, UnsignedIterator last);

/**
 * @brief      Intercala os elementos de um intervalo, em sequencia do começo ao
 *             fim, de modo que o menor de cada posição analisada seja
 *             posicionado no intervalo a cada análise de dois elementos
 *
 * @param      first  Inicio do intervalo a ser ordenado(Primeiro elemento )
 * @param      last   Fim do intervalo a ser ordenado(Último elemento)
 * @param      mid    Metade do intervalo a ser ordenado(Elemento do meio )
 */
void merge_iterator(UnsignedIterator first, UnsignedIterator last, UnsignedIterator mid);

/**
 * @brief      Chama recursivamente o merge_sort_iterator em cada metade do intervalo e
 *             depois chama a função merge para as duas metades do intervalo
 *
 * @param      first  Iterador para o inicio do intervalo a ser ordenado
 * @param      last   Iterador para o fim do intervalo a ser ordenado
 */
void merge_sort_iterator(UnsignedIterator first, UnsignedIterator last);

/**
 * @brief      Percorre o intervalo fazendo trocas de dois elementos a um
 *             determinado gap de distancia (se um for menor que o outro), e
 *             cada iteração diminui esse gap
 *
 * @param      first  Iterador para o inicio do intervalo a ser ordenado
 * @param      last   Iterador para o fim do intervalo a ser ordenado
 */
void shell_sort_iterator(UnsignedIterator first, UnsignedIterator last);

/**
 * @brief      Busca o maior ValueType do intervalo
 *
 * @param      first  Iterador para o inicio do intervalo a ser analisado
 * @param      last   Iterador para o fim do intervalo a ser analisado
 *
 * @return     Maior elemento encontrado
 */
ValueType range_max_iterator(UnsignedIterator first, UnsignedIterator last);

/**
 * @brief      Percorre o vetor 'd' vezes, sendo 'd' o numero de algarismos do
 *             maior número do intervalo, a cada iteração ele agrupa os numeros
 *             com base no digito menos significativo atual, ao fim de cada
 *             iteração ele incrementa qual digito vai ser a base do agrupamento
 *             (1º unidades, 2º dezenas, 3º centenas, e assim por diante)
 *
 * @param      first  Iterador para o inicio do intervalo a ser ordenado
 * @param      last   Iterador para o fim do intervalo a ser ordenado
 */
void radix_sort_iterator(UnsignedIterator first, UnsignedIterator last);

#endif  // INCLUDE_SORTER_IT_HPP_

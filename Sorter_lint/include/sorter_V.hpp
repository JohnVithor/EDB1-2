// Copyright 2018 JV

/**
 * @file sorter_V.hpp
 * @brief      Arquivo com a assinatura das funções de ordenação (Vector) e seus
 *             comentários doxy
 *
 * @author     João Vítor Venceslau Coelho
 * @since      23/09/2017
 * @date       23/03/2018
 */

#ifndef INCLUDE_SORTER_V_HPP_
#define INCLUDE_SORTER_V_HPP_

#include <vector>

using ValueType = unsigned int;
using UnsignedVector = std::vector<ValueType>;

/**
 * @brief      Percorre o intervalo e a cada elemento analisado, o ordena em
 *             relação aos elementos já analisados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void insertion_sort_vector(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Percorre o intervalo em busca do menor elemento e o troca com o
 *             elemento do inicio do intervalo ainda não ordenado
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void selection_sort_vector(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Percorre o vector trocando os elementos maiores com os menores,
 *             de modo que a cada iteração o maior elemento fique no fim do
 *             intervalo não ordenado
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void bubble_sort_vector(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Particiona o intervalo em duas partes, menores que o pivô e
 *             maiores ou iguais ao pivô, o último elemento é escolhido como
 *             pivô
 *
 * @param      vector  Vector com os ValueType a ser "pivotado"
 * @param      left    Inicio do intervalo a ser "pivotado"
 * @param      right   Fim do intervalo a ser "pivotado"
 *
 * @return     Posição do elemento "pivô" após a "pivotagem"
 */
ValueType partition_vector(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Após particionar o intervalo em dois menores, chama o
 *             quick_sort_vector_internal nas duas partições
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void quick_sort_vector_internal(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Retira a última posição do intervalo (é uma posição inválida) e
 *             chama o quick_sort_vector_internal
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void quick_sort_vector(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Intercala os elementos de um intervalo, em sequencia do começo ao
 *             fim, de modo que o menor de cada posição analisada seja
 *             posicionado no intervalo a cada análise de dois elementos
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      mid     Metade do intervalo a ser ordenado ( Elemento do meio )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void merge_vector(UnsignedVector &vector, ValueType left, ValueType mid, ValueType right);

/**
 * @brief      Chama recursivamente o merge_sort_vector_internal em cada metade do
 *             intervalo e depois chama a função merge para as duas metades do
 *             intervalo
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void merge_sort_vector_internal(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Retira a última posição do intervalo (é uma posição inválida) e
 *             chama o merge_sort_vector_internal
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void merge_sort_vector(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Percorre o intervalo fazendo trocas de dois elementos a um
 *             determinado gap de distancia (se um for menor que o outro), e
 *             cada iteração diminui esse gap
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void shell_sort_vector(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Busca o maior ValueType do intervalo
 *
 * @param      vector  Vector a ser analisado
 * @param      left    Inicio do intervalo da busca ( Primeiro elemento )
 * @param      right   Fim do intervalo da busca ( Último elemento )
 *
 * @return     Maior elemento encontrado
 */
ValueType range_max_vector(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Percorre o vector 'd' vezes, sendo 'd' o numero de algarismos do
 *             maior número do intervalo, a cada iteração ele agrupa os numeros
 *             com base no digito menos significativo atual, ao fim de cada
 *             iteração ele incrementa qual digito vai ser a base do agrupamento
 *             (1º unidades, 2º dezenas, 3º centenas, e assim por diante)
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void radix_sort_vector(UnsignedVector &vector, ValueType left, ValueType right);

#endif  // INCLUDE_SORTER_V_HPP_

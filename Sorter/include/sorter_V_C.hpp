/**
 * @file sorter_V_C.hpp
 * @brief      Arquivo com a assinatura das funções de ordenação (Vector) para a
 *             contagem do passos da operação dominante e seus comentários doxy
 *
 * @author     João Vítor Venceslau Coelho
 * @since      08/10/2017
 * @date       14/03/2018
 */

#ifndef SORTER_V_C_H
#define SORTER_V_C_H

#include <vector>

using ValueType = unsigned int;
using UnsignedVector = std::vector<ValueType>;

/**
 * @brief      Percorre o intervalo e a cada elemento analisado, o ordena em
 *             relação aos elementos já analisados
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void insertion_sort_vector_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

/**
 * @brief      Percorre o intervalo em busca do menor elemento e o troca com o
 *             elemento do inicio do intervalo ainda não ordenado
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void selection_sort_vector_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

/**
 * @brief      Percorre o vector trocando os elementos maiores com os menores,
 *             de modo que a cada iteração o maior elemento fique no fim do
 *             intervalo não ordenado
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void bubble_sort_vector_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

/**
 * @brief      Particiona o intervalo em duas partes, menores que o pivô e
 *             maiores ou iguais ao pivô, o último elemento é escolhido como
 *             pivô
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a ser "pivotado"
 * @param      left    Inicio do intervalo a ser "pivotado"
 * @param      right   Fim do intervalo a ser "pivotado"
 * @param      steps   Quantidade de "passos" realizados
 *
 * @return     Posição do elemento "pivô" após a "pivotagem"
 */
ValueType partition_vector_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

/**
 * @brief      Após particionar o intervalo em dois menores, chama o
 *             quick_sort_vector_internal_steps nas duas partições
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 */
void quick_sort_vector_internal_steps(UnsignedVector &vector, ValueType left, ValueType right);

/**
 * @brief      Retira a última posição do intervalo (é uma posição inválida) e
 *             chama o quick_sort_vector_internal_steps
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void quick_sort_vector_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

/**
 * @brief      Intercala os elementos de um intervalo, em sequencia do começo ao
 *             fim, de modo que o menor de cada posição analisada seja
 *             posicionado no intervalo a cada análise de dois elementos
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      mid     Metade do intervalo a ser ordenado ( Elemento do meio )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void merge_vector_steps(UnsignedVector &vector, ValueType left, ValueType mid, ValueType right, ValueType &steps);

/**
 * @brief      Chama recursivamente o merge_sort_V_internal em cada metade do
 *             intervalo e depois chama a função merge para as duas metades do
 *             intervalo
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void merge_sort_vector_internal_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

/**
 * @brief      Retira a última posição do intervalo (é uma posição inválida) e
 *             chama o merge_sort_V_internal
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void merge_sort_vector_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

/**
 * @brief      Percorre o intervalo fazendo trocas de dois elementos a um
 *             determinado gap de distancia (se um for menor que o outro), e
 *             cada iteração diminui esse gap
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void shell_sort_vector_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

/**
 * @brief      Percorre o vector 'd' vezes, sendo 'd' o numero de algarismos do
 *             maior número do intervalo, a cada iteração ele agrupa os numeros
 *             com base no digito menos significativo atual, ao fim de cada
 *             iteração ele incrementa qual digito vai ser a base do agrupamento
 *             (1º unidades, 2º dezenas, 3º centenas, e assim por diante)
 * @details    Esta versão conta o numero de steps realizados
 *
 * @param      vector  Vector com os ValueType a serem ordenados
 * @param      left    Inicio do intervalo a ser ordenado ( Primeiro elemento )
 * @param      right   Fim do intervalo a ser ordenado ( Último elemento )
 * @param      steps   Quantidade de "passos" realizados
 */
void radix_sort_vector_steps(UnsignedVector &vector, ValueType left, ValueType right, ValueType &steps);

#endif
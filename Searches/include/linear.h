/**
* @file		linear.h
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	15/08/2017
* @date		24/08/2017
* @sa		
*/

#ifndef LINEAR_H
#define LINEAR_H

/**
* @brief Função que busca um elemento em um vetor, elemento a elemento
* @param[in] first_ Ponteiro para o primeiro elemento do vetor
* @param[in] last_ Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Caso o elemento seja encontrado: ponteiro para o elemento no vetor, senão: last_
*/
int * linear_search (int * first_, int * last_, int target);

/**
* @brief Função que busca um elemento em um vetor, elemento a elemento
* @param[in] first_ Ponteiro para o primeiro elemento do vetor
* @param[in] last_ Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Caso o elemento seja encontrado: ponteiro para o elemento no vetor, senão: last_
*/
int * linear_search_sorted (int * first_, int * last_, int target);

/**
* @brief Função que busca um elemento em um vetor, elemento a elemento de forma recursiva
* @param[in] first_ Ponteiro para o primeiro elemento do vetor
* @param[in] last_ Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Caso o elemento seja encontrado: ponteiro para o elemento no vetor, senão: last_
*/
int * linear_search_recursive (int * first_, int * last_, int target);

#endif
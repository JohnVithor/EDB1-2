/**
* @file		binary.h
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	15/08/2017
* @date		24/08/2017
* @sa		
*/

#ifndef BINARY_H
#define BINARY_H

/**
* @brief Função que chama binary_search_recursive_internal
* @param[in] first_ Ponteiro para o primeiro elemento do vetor
* @param[in] last_ Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Caso o elemento seja encontrado: ponteiro para o elemento no vetor, senão: ultimo
*/
int * binary_search_recursive (int *primeiro, int *ultimo, int target);
/**
* @brief Função que busca recursivamente um elemento em um vetor, sempre diminuindo o intervalo de busca ao meio
* @param[in] primeiro Ponteiro para o primeiro elemento do vetor
* @param[in] ultimo Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Ponteiro para o elemento no vetor
*/
int * binary_search_recursive_internal (int *primeiro, int *ultimo, int target);

/**
* @brief Função que busca um elemento em um vetor, sempre diminuindo o intervalo de busca ao meio
* @param[in] first_ Ponteiro para o primeiro elemento do vetor
* @param[in] last_ Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Caso o elemento seja encontrado: ponteiro para o elemento no vetor, senão: last_
*/
int * binary_search_P(int* first_,int* last_, int target);

#endif
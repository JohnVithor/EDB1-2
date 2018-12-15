/**
* @file		ternary.h
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	15/08/2017
* @date		24/08/2017
* @sa		
*/

#ifndef TERNARY_H
#define TERNARY_H

/**
* @brief Função que chama ternary_search_recusirve_internal
* @param[in] first_ Ponteiro para o primeiro elemento do vetor
* @param[in] last_ Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Caso o elemento seja encontrado: ponteiro para o elemento no vetor, senão: last_
*/
int * ternary_search_recusirve (int *primeiro, int *ultimo, int target);

/**
* @brief Função que busca recursivamente um elemento em um vetor, sempre diminuindo o intervalo de busca em um terço do anterior
* @param[in] first_ Ponteiro para o primeiro elemento do vetor
* @param[in] last_ Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Ponteiro para o elemento no vetor
*/
int * ternary_search_recusirve_internal (int *primeiro, int *ultimo, int target);

/**
* @brief Função que busca um elemento em um vetor, sempre diminuindo o intervalo de busca em um terço do anterior
* @param[in] first_ Ponteiro para o primeiro elemento do vetor
* @param[in] last_ Ponteiro para o ultimo elemento do vetor
* @param[in] target Elemento a ser procurado
* @return Caso o elemento seja encontrado: ponteiro para o elemento no vetor, senão: last_
*/
int * ternary_search_P(int* first_,int* last_, int target); // Não está funcionando

#endif
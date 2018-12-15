/**
 * @file alloc.hpp
 * @brief      Arquivo com a assinatura das funções de teste de alocação e seus
 *             comentários doxy
 *
 * @author     João Vítor Venceslau Coelho
 * @since      30/09/2017
 * @date       14/03/2018
 */
#ifndef ALLOC_H_
#define ALLOC_H_

using ValueType = unsigned int;

/**
 * @brief      Testa se um array com o tamanho especificado pode ser alocado
 * @details    Tenta alocar um array de ValueType, captura uma exceção em
 *             caso de falha
 *
 * @param      tam   Tamanho do array que será tentada a alocação
 *
 * @return     true se a alocação foi bem sucedida, false se não foi possível
 *             alocar
 */
bool test_alloc(ValueType tam);

/**
 * @brief      Testa qual é o maior array que pode ser alocado ( em potencias de
 *             2 )
 * @details    Tenta alocar varios arrays, sempre dobrando o tamanho anterior
 *
 * @return     Tamanho do maior array alocado
 */
ValueType alloc_greater();

#endif
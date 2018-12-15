/**
* @file		vector_Iterators_Capacity.hpp
* @brief	Implementação do métodos relacionados com iteradores e capacidade de armazenamento da classe sc::vector 
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/10/2017
* @date		21/10/2017	
*/

#include "vector.hpp"

//										========= VECTOR =========
// [II] Iterators

template < typename value_type >
iterator< value_type > sc::vector< value_type >::begin( void )
{
	return iterator( &m_storage[0] );
}

template < typename value_type >
iterator< value_type > sc::vector< value_type >::end( void )
{
	return iterator( &m_storage[m_end]);
}

template < typename value_type >
const_iterator<value_type> sc::vector< value_type >::cbegin( void ) const
{
	return const_iterator( &m_storage[0] );
}

template < typename value_type >
const_iterator<value_type> sc::vector< value_type >::cend( void ) const
{
	return const_iterator( &m_storage[m_end]);
}

//	[III] Capacity

template < typename value_type >
size_type sc::vector< value_type >::size( void )
{
	return m_end;
}

template < typename value_type >
size_type sc::vector< value_type >::capacity( void )
{
	return m_capacity;
}

template < typename value_type >
bool sc::vector< value_type >::empty ( void )
{
	return m_end == 0;
}
/**
* @file		vector_Element_Access.hpp
* @brief	Implementação do métodos de acesso a elementos da classe sc::vector
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/10/2017
* @date		21/10/2017	
*/

#include "vector.hpp"

//										========= VECTOR =========
// [V] Element access

template < typename value_type >
reference<value_type> sc::vector< value_type >::back( void )
{
	return *--end();
}

template < typename value_type >
reference<value_type> sc::vector< value_type >::front(void)
{
	return *begin();
}

template < typename value_type >
const_reference<value_type> sc::vector< value_type >::back( void ) const
{
	return *--cend();
}

template < typename value_type >
const_reference<value_type> sc::vector< value_type >::front( void ) const
{
	return *cbegin();
}

template < typename value_type >
reference<value_type> sc::vector< value_type >::operator[]( size_type id )
{
	return m_storage[ id ];
}

template < typename value_type >
const_reference<value_type> sc::vector< value_type >::operator[]( size_type id ) const
{
	return m_storage[ id ];
}

template < typename value_type >
reference<value_type> sc::vector< value_type >::at( size_type id )
{
	if ( id > m_end )
		throw std::out_of_range("vector::at() -> acesso fora do vetor!");
	return m_storage[ id ];
}

template < typename value_type >
const_reference<value_type> sc::vector< value_type >::at( size_type id ) const
{
	if ( id > m_end )
		throw std::out_of_range("vector::at() -> acesso fora do vetor!");
	return m_storage[ id ];
}

template < typename value_type >
pointer<value_type> sc::vector< value_type >::data( void )
{
	//return m_storage.get();
	return m_storage;
}

template < typename value_type >
const_pointer<value_type> sc::vector< value_type >::data( void ) const
{
	//return m_storage.get();
	return m_storage;
} 
/**
* @file		vector_Special_Members.hpp
* @brief	Implementação do métodos especiais da classe sc::vector
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/10/2017
* @date		21/10/2017	
*/

#include "vector.hpp"

//										========= VECTOR =========
// [I] SPECIAL MEMBERS

template < typename value_type >
sc::vector< value_type >::vector()
	: m_storage( new value_type)
	, m_end(0)
	, m_capacity(1)
{ /* vazio */ }

template < typename value_type >
sc::vector< value_type >::vector( std::size_t cap )
	: m_storage(new value_type[cap])
	, m_end(0)
	, m_capacity(cap)
{ /* vazio */ }

template < typename value_type >
template < typename InputItr >
sc::vector< value_type >::vector( InputItr first, InputItr last)
{
	size_type distance = last - first;

	m_end = distance;
	m_capacity = distance;
	m_storage = new value_type[distance];

	std::copy( first, last, m_storage );
}

template < typename value_type >
sc::vector< value_type >::vector( const vector & other )
{
	m_capacity = other.m_capacity;
	m_end = other.m_end;
	m_storage = new value_type[m_capacity];
	
	for (auto i = 0u; i < m_end; ++i )
	{
		m_storage[i] = other.m_storage[i];
	}


}

template < typename value_type >
sc::vector< value_type >::vector( std::initializer_list< value_type > ilist )
{
	m_capacity = ilist.size();
	m_storage = new value_type[m_capacity];
	m_end = 0;
	
	for( auto i = 0u ; i < m_capacity ; ++i )
		m_storage[i] = value_type();
	
	for (const_pointer it = ilist.begin(); it != ilist.end() ; ++it, ++m_end)
	{
		m_storage[m_end] = *it;
	}

}

template < typename value_type >
sc::vector< value_type >& sc::vector< value_type >::operator=( const vector& other )
{
	m_capacity = other.m_capacity;
	m_end = other.m_end;
	m_storage = new value_type[m_capacity];
	
	for (auto i = 0u; i < m_end; ++i )
	{
		m_storage[i] = other.m_storage[i];
	}
	return *this;
}

template < typename value_type >
sc::vector< value_type >& sc::vector< value_type >::operator=( std::initializer_list< value_type > ilist )
{
	reserve(ilist.size());
	m_end = 0;
	
	for( auto i = 0u ; i < m_capacity ; ++i )
		m_storage[i] = value_type();
	
	for (const_pointer it = ilist.begin(); it != ilist.end() ; ++it, ++m_end)
	{
		m_storage[m_end] = *it;
	}

	return *this;
}
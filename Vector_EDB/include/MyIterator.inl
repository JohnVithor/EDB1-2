/**
* @file		MyIterator.hpp
* @brief	Implementação do métodos da classe sc::MyIterator 
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/10/2017
* @date		21/10/2017	
*/

#include "vector.hpp"

typedef std::ptrdiff_t difference_type;

typedef std::size_t size_type;

template < typename value_type >
using iterator = sc::MyIterator< value_type >;

template < typename value_type >
using const_iterator = sc::MyIterator< const value_type >;

template < typename value_type >
using pointer = value_type*;

template < typename value_type >
using const_pointer = const value_type*;

template < typename value_type >
using u_pointer = std::unique_ptr< value_type > ;

template < typename value_type >
using const_u_pointer = std::unique_ptr< const value_type > ;

template < typename value_type >
using reference = value_type&;

template < typename value_type >
using const_reference = const value_type&;

//									========= MyIterator =========

template < typename value_type >
sc::MyIterator< value_type >::MyIterator( pointer ptr)
		: m_ptr(ptr)
{ /* Vazio */ }

//template < typename value_type >
//sc::MyIterator< value_type >::~MyIterator();

template < typename value_type >
iterator<value_type> sc::MyIterator< value_type >::operator++(void)
{
	assert( m_ptr != nullptr );
	++m_ptr;
	return *this;
}

template < typename value_type >
iterator<value_type> sc::MyIterator< value_type >::operator++(int)
{
	iterator<value_type> temp( *this );
	++m_ptr;
	return temp;
}

template < typename value_type >
iterator<value_type> sc::MyIterator< value_type >::operator--(void)
{
	assert( m_ptr != nullptr );
	--m_ptr;
	return *this;
}

template < typename value_type >
iterator<value_type> sc::MyIterator< value_type >::operator--(int)
{
	iterator<value_type> temp( *this );
	--m_ptr;
	return temp;
}

template < typename value_type >
iterator<value_type> sc::MyIterator< value_type >::operator+( size_type num )
{
	return iterator<value_type>( m_ptr + num );
}

template < typename value_type >
iterator<value_type> sc::MyIterator< value_type >::operator-( size_type num )
{
	return iterator<value_type>( m_ptr - num );
}

template < typename value_type >
value_type& sc::MyIterator< value_type >::operator*(void)
{
	assert( m_ptr != nullptr );
	return *m_ptr;
}

template < typename value_type >
const value_type& sc::MyIterator< value_type >::operator*(void) const
{
	assert( m_ptr != nullptr );
	return *m_ptr;
}

template < typename value_type >
difference_type sc::MyIterator< value_type >::operator-( const sc::MyIterator<value_type>& other )
{
	return m_ptr - other.m_ptr;
}

template < typename value_type >
bool sc::MyIterator< value_type >::operator==(const iterator< value_type >& other) const
{
	return m_ptr == other.m_ptr;
}

template < typename value_type >
bool sc::MyIterator< value_type >::operator!=(const iterator< value_type >& other) const
{
	return m_ptr != other.m_ptr;
}

template < typename value_type >
bool sc::MyIterator< value_type >::operator==(const_pointer other) const
{
	return m_ptr == other;
}

template < typename value_type >
bool sc::MyIterator< value_type >::operator!=(const_pointer other) const
{
	return m_ptr != other;
}
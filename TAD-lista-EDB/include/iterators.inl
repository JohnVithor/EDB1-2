/**
* @file		iterators.inl
* @brief	Implementação dos métodos das classes ls::list::const_iterator e ls::list::iterator
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/11/2017
* @date		18/11/2017	
*/

#include "list.hpp"

//										==========================
//										===== Const Iterator =====

template < typename T >
const T & ls::list< T >::const_iterator::operator*( ) const 
{
	if ( this->current == nullptr )
	{
		throw std::out_of_range("operator* -> O iterador está em nullptr");
	}
	return this->current->data;
}

template < typename T >
typename ls::list< T >::const_iterator& ls::list< T >::const_iterator::operator++( ) 
{
	if ( this->current != nullptr )
	{
		this->current = this->current->next;
	}
	return *this;
}

template < typename T >
typename ls::list< T >::const_iterator ls::list< T >::const_iterator::operator++( int ) 
{
	if ( this->current != nullptr )
	{
		auto aux = *this;
		this->current = this->current->next;
		return aux;
	}
	return *this;
}

template < typename T >
typename ls::list< T >::const_iterator& ls::list< T >::const_iterator::operator--( ) 
{
	if ( this->current != nullptr )
	{
		this->current = this->current->prev;
	}
	return *this;
}

template < typename T >
typename ls::list< T >::const_iterator ls::list< T >::const_iterator::operator--( int ) 
{
	if ( this->current != nullptr )
	{
		auto aux = *this;
		this->current = this->current->prev;
		return aux;
	}
	return *this;
}

template < typename T >
typename ls::list< T >::const_iterator ls::list< T >::const_iterator::operator+( size_type num )
{
	const_iterator temp = *this;
	for ( size_type i = 0; i < num; ++i)
	{
		if ( temp.current == nullptr )
		{
			throw std::out_of_range("operator+ -> O iterador está em nullptr");
		}
		temp.current = temp.current->next;	
	}
	return temp;
}

template < typename T >
typename ls::list< T >::const_iterator ls::list< T >::const_iterator::operator-( size_type num )
{
	const_iterator temp = *this;
	for ( size_type i = 0; i < num; ++i)
	{
		if ( temp.current == nullptr )
		{
			throw std::out_of_range("operator- -> O iterador está em nullptr");	
		}
		temp.current = temp.current->prev;	
	}
	return temp;
}

template < typename T >
bool ls::list< T >::const_iterator::operator==( const const_iterator & rhs ) const
{
	return ( this->current == rhs.current );
}

template < typename T >
bool ls::list< T >::const_iterator::operator!=( const const_iterator & rhs ) const
{
	return (not (*this == rhs) );
}

//										====================
//										===== Iterator =====

template < typename T >
const T & ls::list< T >::iterator::operator*( ) const 
{
	if ( this->current == nullptr )
	{
		throw std::out_of_range("operator* -> O iterador está em nullptr");
	}
	return this->current->data;
}

template < typename T >
T & ls::list< T >::iterator::operator*( ) 
{
	if ( this->current == nullptr )
	{
		throw std::out_of_range("operator* -> O iterador está em nullptr");
	}
	return this->current->data;
}

template < typename T >
typename ls::list< T >::iterator& ls::list< T >::iterator::operator++( ) 
{
	if ( this->current != nullptr )
	{
		this->current = this->current->next;
	}
	return *this;
}

template < typename T >
typename ls::list< T >::iterator ls::list< T >::iterator::operator++( int ) 
{
	if ( this->current != nullptr )
	{
		auto aux = *this;
		this->current = this->current->next;
		return aux;
	}
	return *this;
}

template < typename T >
typename ls::list< T >::iterator& ls::list< T >::iterator::operator--( ) 
{
	if ( this->current != nullptr )
	{
		this->current = this->current->prev;
	}
	return *this;
}

template < typename T >
typename ls::list< T >::iterator ls::list< T >::iterator::operator--( int ) 
{
	if ( this->current != nullptr )
	{
		auto aux = *this;
		this->current = this->current->prev;
		return aux;
	}
	return *this;
}
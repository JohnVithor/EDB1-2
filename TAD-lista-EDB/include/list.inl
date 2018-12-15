/**
* @file		list.inl
* @brief	Implementação dos métodos da classe ls::list
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/11/2017
* @date		25/11/2017	
*/

#include <iostream>
#include "list.hpp"

using size_type = unsigned long;

//											===========================
//											===== SPECIAL MEMBERS =====

template < typename T >
ls::list< T >::list()
		:m_head( new Node() )
		,m_tail( new Node() )
		,m_size( 0 )
{
	m_head->next = m_tail;
	m_tail->prev = m_head;
}

template < typename T >
ls::list< T >::list( size_type count )
		:m_head( new Node() )
		,m_tail( new Node() )
		,m_size( count )
{
	m_head->next = m_tail;
	m_tail->prev = m_head;

	Node * temp = m_head;
	while( count-- > 0 )
	{
		Node * aux = new Node( T(), temp, temp->next );
		temp->next->prev = aux;
		temp->next = aux;
		temp = temp->next;
	}
}

template < typename T >
template < typename InputItr >
ls::list< T >::list ( InputItr first, InputItr last)
		:m_head( new Node() )
		,m_tail( new Node() )
		,m_size( 0 )
{
	m_head->next = m_tail;
	m_tail->prev = m_head;

	while( first != last )
	{
		push_back( *first );
		++first;
	}
}

template < typename T >
ls::list< T >::list ( const ls::list< T > & other)
		:m_head( new Node() )
		,m_tail( new Node() )
		,m_size( 0 )
{
	m_head->next = m_tail;
	m_tail->prev = m_head;

	for( auto it( other.cbegin() ); it != other.cend(); ++it )
	{
		push_back( *it );
	}
}

template < typename T >
ls::list< T >::list ( std::initializer_list< T > ilist )
		:m_head( new Node() )
		,m_tail( new Node() )
		,m_size( 0 )
{
	m_head->next = m_tail;
	m_tail->prev = m_head;

	for( auto it( ilist.begin() ); it != ilist.end(); ++it )
	{
		push_back( *it );
	}
}

template < typename T >
ls::list< T >::~list()
{
	Node * aux = m_head->next;

	while ( aux != m_tail )
	{
		Node * temp = aux;
		aux = aux->next;
		delete temp;
	}

	delete m_head;
	delete m_tail;
}

template < typename T >
ls::list< T >& ls::list< T >::operator=( const list& other )
{
	clear();

	for( auto it( other.cbegin() ); it != other.cend(); ++it )
	{
		push_back( *it );
	}
	return *this;
}

template < typename T >
ls::list< T >& ls::list< T >::operator=( std::initializer_list< T > ilist )
{
	clear();

	for( auto it( ilist.begin() ); it != ilist.end(); ++it )
	{
		push_back( *it );
	}
	return *this;
}

//											=====================
//											===== Iterators =====

template < typename T >
typename ls::list< T >::iterator ls::list< T >::begin( void )
{
	return iterator( m_head->next );
}

template < typename T >
typename ls::list< T >::iterator ls::list< T >::end( void )
{
	return iterator( m_tail );
}

template < typename T >
typename ls::list< T >::const_iterator ls::list< T >::cbegin( void ) const
{
	return const_iterator( m_head->next );
}

template < typename T >
typename ls::list< T >::const_iterator ls::list< T >::cend( void ) const
{
	return const_iterator( m_tail );
}

//										====================
//										===== Capacity =====

template < typename T >
size_type ls::list< T >::size( void ) const
{
	return m_size;
}

template < typename T >
bool ls::list< T >::empty ( void ) const
{
	return m_size == 0;
}

//										=====================
//										===== Modifiers =====

template < typename T >
void ls::list< T >::clear ( void )
{
	Node * aux = m_head->next;

	while ( aux != m_tail )
	{
		Node * temp = aux;
		aux = aux->next;
		delete temp;
	}
	m_size = 0;
	m_head->next = m_tail;
	m_tail->prev = m_head;
}

template < typename T >
T & ls::list< T >::front(void)
{
	if ( empty() )
	{
		throw std::out_of_range("front() -> A lista está vazia!");
	}
	return m_head->next->data;
}

template < typename T >
const T & ls::list< T >::front( void ) const
{
	if ( empty() )
	{
		throw std::out_of_range("front() -> A lista está vazia!");
	}
	return m_head->next->data;
}

template < typename T >
T & ls::list< T >::back( void )
{
	if ( empty() )
	{
		throw std::out_of_range("back() -> A lista está vazia!");
	}
	return m_tail->prev->data;
}

template < typename T >
const T & ls::list< T >::back( void ) const
{
	if ( empty() )
	{
		throw std::out_of_range("back() -> A lista está vazia!");
	}
	return m_tail->prev->data;
}

template <typename T >
void ls::list< T >::push_front ( const T & value )
{
	Node * new_node = new Node( value, m_head, m_head->next );
	m_head->next->prev = new_node;
	m_head->next = new_node;
	++m_size;
}

template < typename T >
void ls::list< T >::push_back ( const T & value )
{
	Node *  new_node = new Node( value, m_tail->prev, m_tail );
	m_tail->prev->next = new_node;
	m_tail->prev = new_node;
	++m_size;
}

template <typename T >
void ls::list< T >::pop_front ( void )
{
	if ( empty() )
	{
		throw std::out_of_range("pop_front() -> A lista está vazia!");
	}

	m_head->next->next->prev = m_head;

	Node * temp = m_head->next->next;
	delete m_head->next;

	m_head->next = temp;
	--m_size;
}

template <typename T >
void ls::list< T >::pop_back ( void )
{
	if ( empty() )
	{
		throw std::out_of_range("pop_back() -> A lista está vazia!");
	}

	m_tail->prev->prev->next = m_tail;

	Node * temp = m_tail->prev->prev;
	delete m_tail->prev;

	m_tail->prev = temp;
	--m_size;
}

template <typename T >
void ls::list< T >::assign( const T& value )
{
	if ( empty() )
	{
		throw std::out_of_range("assign() -> A lista está vazia!");
	}
	Node * temp = m_head->next;
	while ( temp != m_tail )
	{
		temp->data = value;
		temp = temp->next;
	}
}

//											=====================
//											==== Overloading ====

template < typename T >
bool ls::list< T >::operator==( const list& other )
{
	if( m_size != other.m_size )
	{
		return false;
	}
	else
	{
		auto it1( cbegin() );
		auto it2( other.cbegin() );
		while ( it1 != cend() )
		{
			if( *it1 != *it2 )
			{
				return false;
			}
			++it1;
			++it2;
		}
	}

	return true;
}

template < typename T >
bool ls::list< T >::operator!=( const list& other )
{
	return (not ( *this == other));
}

//										======================
//										==== Modifiers IT ====

template < typename T >
void ls::list< T >::assign( size_type count, const T& value )
{
	if ( empty() )
	{
		throw std::out_of_range("assign() -> A lista está vazia!");
	}

	Node * temp = m_head->next;

	size_type copies = 0;
	while ( temp != this->m_tail and copies != count )
	{
		temp->data = value;
		temp = temp->next;
		++copies;
	}
}


template < typename T >
template < typename InputItr >
void ls::list< T >::assign( InputItr first, InputItr last )
{
	if ( empty() )
	{
		throw std::out_of_range("assign() -> A lista está vazia!");
	}

	Node * temp = m_head->next;
	auto elemento_atual = first;

	while ( temp != this->m_tail )
	{
		temp->data = *elemento_atual;
		temp = temp->next;
		++elemento_atual;

		if ( elemento_atual == last )
		{
			elemento_atual = first;
		}
	}
}

template <typename T >
void ls::list< T >::assign( std::initializer_list< T > ilist )
{
	if ( empty() )
	{
		throw std::out_of_range("assign() -> A lista está vazia!");
	}

	Node * temp = m_head->next;
	auto elemento_atual = ilist.begin();

	while ( temp != this->m_tail )
	{
		temp->data = *elemento_atual;
		temp = temp->next;
		++elemento_atual;

		if ( elemento_atual == ilist.end() )
		{
			elemento_atual = ilist.begin();
		}
	}
}

template < typename T >
typename ls::list< T >::iterator ls::list< T >::insert ( const_iterator itr, const T & value )
{
	Node * new_node = new Node( value, itr.current->prev, itr.current );
	
	itr.current->prev->next = new_node;
	itr.current->prev = new_node;
	
	++m_size;
	
	return iterator( new_node );
}

template < typename T >
template < typename InputItr >
typename ls::list< T >::iterator ls::list< T >::insert ( const_iterator pos, InputItr first, InputItr last)
{
	iterator aux;
	while( first != last )
	{
		aux = insert( pos, *first );
		++first;
	}
		
	return aux;
}

template <typename T >
typename ls::list< T >::iterator ls::list< T >::insert ( const_iterator pos, std::initializer_list< T > ilist)
{
	iterator aux;
	for (auto i = ilist.begin(); i != ilist.end(); ++i )
	{
		aux = insert( pos, *i );
	}

	return aux;
}

template < typename T >
typename ls::list< T >::iterator ls::list< T >::erase ( const_iterator itr )
{
	if ( empty() )
	{
		throw std::out_of_range("erase() -> A lista está vazia!");
	}

	Node * temp = itr.current->next;

	temp->prev = ( itr.current->prev );
	itr.current->prev->next = temp;

	delete itr.current;

	--m_size;

	return iterator( temp );
}

template < typename T >
typename ls::list< T >::iterator ls::list< T >::erase ( const_iterator first, const_iterator last )
{
	if ( empty() )
	{
		throw std::out_of_range("erase() -> A lista está vazia!");
	}

	++first;
	while( first != last )
	{
		erase( first.current->prev );
		++first;
	}

	return erase( last.current->prev );;
}

template <typename T>
typename ls::list< T >::const_iterator ls::list< T >::find ( const T & value ) const
{
	auto aux = m_head->next;
	while ( aux != m_tail )
	{
		if( aux->data == value )
		{
			return const_iterator( aux );
		}
		aux = aux->next;
	}

	return const_iterator( m_tail );
}


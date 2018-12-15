/**
* @file		vector_Modifiers.hpp
* @brief	Implementação do métodos de modificação da classe sc::vector 
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/10/2017
* @date		21/10/2017	
*/

#include "vector.hpp"

//										========= VECTOR =========
// [IV] Modifiers

template <typename value_type >
void sc::vector< value_type >::clear ( void )
{
	//assign(value_type());
	m_end = 0;
}

template <typename value_type >
void sc::vector< value_type >::push_front ( const_reference value )
{
	if ( m_end == m_capacity ) 
	{
		reserve( 2*m_capacity );
	}
	std::copy( m_storage, m_storage+m_end, m_storage+1 );

	m_storage[0] = value;
	++m_end;
}

template < typename value_type >
void sc::vector< value_type >::push_back (const_reference value )
{
	if ( m_end == m_capacity )
	{
		reserve( 2*m_capacity );
	}
	m_storage[ m_end++ ] = value;
	
}

template <typename value_type >
void sc::vector< value_type >::pop_back ( void )
{
	if ( empty() )
	{
		throw std::out_of_range("[pop_back()]: Cannot recover an element from an empty vector!");
	}
	else
	{
		--m_end;
	}
}

template <typename value_type >
void sc::vector< value_type >::pop_front ( void )
{
	if ( empty() )
	{
		throw std::out_of_range("[pop_front()]: Cannot recover an element from an empty vector!");
	}
	else
	{
		std::copy( m_storage+1, m_storage+m_end, m_storage );
		--m_end;	
	}
	
}

template < typename value_type >
iterator< value_type > sc::vector< value_type >::insert ( iterator it, const value_type& value )
{
	if ( m_end == m_capacity )
	{
		reserve( 2*m_capacity );
	}

	std::copy(it, it+m_end, it+1);
	*it = value;
	++m_end;

	return it;
}

template < typename value_type >
template < typename InputItr >
iterator< value_type > sc::vector< value_type >::insert ( iterator itrt, InputItr first, InputItr last)
{
	size_type interval_size = (last - first);	// tamanho do intervalo a ser inserido
	auto dist_itrt = itrt - begin();				// distancia do iterador para o começo do vector

	while ( (m_end + interval_size) > m_capacity )
	{ 
		reserve(2*m_capacity);
	}

	std::copy(&m_storage[dist_itrt], &m_storage[m_end], &m_storage[dist_itrt+interval_size]);
	while(first != last)
	{
		m_storage[dist_itrt++] = *first++;
	}

	m_end+=interval_size;

	return end();
}

template <typename value_type >
iterator< value_type > sc::vector< value_type >::insert ( iterator itrt, std::initializer_list< value_type > ilist)
{
	size_type list_size = ilist.size();			// tamanho da lista inicializadora
	auto dist_itrt = itrt - begin();				// distancia do iterador para o começo do vector
	
	while ( (m_end + list_size) > m_capacity )
	{
		reserve(2*m_capacity);	
	}

	std::copy(&m_storage[dist_itrt], &m_storage[m_end], &m_storage[dist_itrt+list_size]);

	for (auto it(ilist.begin()); it != ilist.end(); ++it)
	{
		m_storage[dist_itrt++] = *it;
	}

	m_end += list_size;

	return end();
}

template < typename value_type >
void sc::vector< value_type >::reserve (size_type new_cap)
{
	if (new_cap <= m_capacity)
	{
		return;
	}
	pointer temp = new value_type[new_cap];

	std::copy(begin(), begin()+m_end, temp);

	delete[] m_storage;
	m_storage = temp;
	m_capacity = new_cap;

	for (size_type i = m_end; i < m_capacity; ++i)
	{
		m_storage[i] = value_type();
	}
}

template <typename value_type >
void sc::vector< value_type >::shrink_to_fit( void )
{
	pointer temp = new value_type[m_end];

	std::copy(begin(), begin()+m_end, temp);

	delete m_storage;
	m_storage = temp;
	m_capacity = m_end;
}

template <typename value_type >
void sc::vector< value_type >::assign( const_reference value)
{
	if ( empty() )
		throw std::out_of_range("vector::assign() -> O vetor está vazio!");

	for (size_type i = 0u; i <= m_end; ++i)
		m_storage[i] = value;
}

template <typename value_type >
void sc::vector< value_type >::assign( std::initializer_list< value_type > ilist )
{
	if ( empty() )
		throw std::out_of_range("vector::assign() -> O vetor está vazio!");

	size_type i = 0;
	auto elemento_atual = ilist.begin();
	for (auto it = begin(); it != end(); ++it,++i)
	{
		*it = *elemento_atual;
		++elemento_atual;
		if (elemento_atual == ilist.end())
		{
			elemento_atual = ilist.begin();
		}
	}
}

template < typename value_type >
template < typename InputItr >
void sc::vector< value_type >::assign( InputItr first, InputItr last )
{
	if ( empty() )
		throw std::out_of_range("vector::assign() -> O vetor está vazio!");

	size_type i = 0;
	auto elemento_atual = first;
	for (auto it = begin(); it != end(); ++it,++i)
	{
		*it = *elemento_atual;
		++elemento_atual;
		if (elemento_atual == last)
		{
			elemento_atual = first;
		}
	}
}

template < typename value_type >
iterator< value_type > sc::vector< value_type >::erase ( iterator first, iterator last )
{
	size_type dist = last - first;
	std::copy(last, end(), first);
	for (auto it = end() - dist; it != end(); ++it)
	{
		*it = value_type();
	}
	m_end -= dist;
	return end();
}

template < typename value_type >
iterator< value_type > sc::vector< value_type >::erase ( iterator itrt )
{
	std::copy(itrt+1, end(), itrt);
	m_end--;

	return end();
}
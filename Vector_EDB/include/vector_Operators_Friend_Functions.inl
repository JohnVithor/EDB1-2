/**
* @file		vector_Operators_Friend_Functions.hpp
* @brief	Implementação da sobrecarga de alguns operadores e das funções friend da classe sc::vector 
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/10/2017
* @date		21/10/2017	
*/

#include "vector.hpp"

//										========= VECTOR =========
// [VI] Operators

template < typename value_type >
bool sc::vector< value_type >::operator==( const vector & other) const
{
	if ( m_end != other.m_end or m_capacity != other.m_capacity)
	{
		return false;
	}
	for ( size_type i = 0; i < m_end; i++ )
	{
		if (m_storage[i] != other.m_storage[i])
		{
			return false;
		} 
	}

	return true;
}

template < typename value_type >
bool sc::vector< value_type >::operator!=( const vector & other) const
{
	return !(*this == other);
}

// [VII] Friend functions.

template <typename value_type>
void sc::vector<value_type>::swap ( vector< value_type > & other ) 
{
	sc::vector< value_type > temp(*this);
	*this = other;
	other = temp;
}

template <typename value_type>
void sc::vector<value_type>::print () const 
{
	std::cout << "[ ";
	for( size_type i = 0 ; i < m_end ; ++i )
		std::cout << m_storage[i] << " ";
	std::cout << "| ";
	for( size_type i = m_end ; i < m_capacity ; ++i )
		std::cout << m_storage[i] << " ";
	std::cout << "]";
	std::cout << " Tamanho Lógico: " << m_end << ", Tamanho Físico: " << m_capacity << ".\n";

}
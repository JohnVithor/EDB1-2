/**
 * @file hashtbl.inl
 * @brief      Implementação dos métodos da classe HashTbl
 * @details    { detailed_item_description }
 *
 * @author     João Vítor Venceslau Coelho / Selan Rodrigues dos Santos
 * @since      02/12/2017
 * @date       05/12/2017
 */

using namespace ac;

template< class KeyType, class DataType>
using Entry = HashEntry<KeyType,DataType> ;

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::HashTbl( int TableSz_ )
{
	bool eh_primo = false;
	while ( eh_primo != true )
	{
		eh_primo = true;
		if (TableSz_ % 2 == 0 )
		{
			++TableSz_;
			eh_primo = false;
			continue;
		}
		for ( int i = 3; i < TableSz_/2; i+=2 )
		{
			if ( TableSz_ % i == 0 )
			{
				eh_primo = false;
				++TableSz_;
			}
		}
	}
	m_count = 0;
	m_size = TableSz_;
	m_data_table = new std::list< Entry >[m_size];
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::~HashTbl()
{
	for ( unsigned int i = 0; i < m_size; ++i)
	{
		auto pos = (m_data_table+i);
		if ( not pos->empty() )
		{
			pos->clear();
		}
	}
	delete[] m_data_table;
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::insert( const KeyType & k_, const DataType & d_ )
{
	if ( m_count/m_size > 1 )
	{
		rehash();
	}

	KeyHash  hashFunc;
	KeyEqual equalFunc;
	Entry new_entry( k_, d_ );

	auto end( hashFunc( k_ ) % m_size );

	auto pos = m_data_table + end;

	for ( auto it = pos->begin(); it != pos->end(); ++it)
	{
		if ( true == equalFunc ( it->m_key, new_entry.m_key ) )
		{
			*it = new_entry;
			return false;
		}		
	}
	pos->push_back( new_entry );
	++m_count;
	return true;
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::remove( const KeyType & k_ )
{
	KeyHash  hashFunc;
	KeyEqual equalFunc;
	auto end( hashFunc( k_ ) % m_size );
	auto pos = m_data_table + end;
	if ( not pos->empty() )
	{
		for ( auto it = pos->begin(); it != pos->end(); ++it)
		{
			if ( true == equalFunc ( it->m_key, k_ ) )
			{
				pos->erase(it);
				--m_count;
				return true;
			}		
		}	
	}
	return false;
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::retrieve( const KeyType & k_, DataType & d_ ) const
{
	KeyHash  hashFunc;
	KeyEqual equalFunc;
	auto end( hashFunc( k_ ) % m_size );
	auto pos = m_data_table + end;
	if ( not pos->empty() )
	{
		for ( auto it = pos->begin(); it != pos->end(); ++it)
		{
			if ( true == equalFunc ( it->m_key, k_ ) )
			{
				d_ = it->m_data;
				return true;
			}		
		}	
	}
	return false;
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
void HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::clear( void )
{
	for ( unsigned int i = 0; i < m_size; ++i)
	{
		auto pos = (m_data_table+i);
		if ( not pos->empty())
		{
			pos->clear();
		}
	}
	m_count = 0;
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::empty( void ) const
{
	return ( m_count == 0 );
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
void HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::print1() const
{
	for ( unsigned int i = 0; i < m_size; ++i)
	{
		auto pos = (m_data_table+i);
		if ( not pos->empty())
		{
			std::cout << "Localização na Hash Table: " << i << std::endl;
			for ( auto it = pos->begin(); it != pos->end(); ++it)
			{
				std::cout << it->m_key << ", " << it->m_data << std::endl;
			}
			std::cout << std::endl;
		}
	}
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
void HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::print2() const
{
	for ( unsigned int i = 0; i < m_size; ++i)
	{
		auto pos = (m_data_table+i);
		if ( not pos->empty())
		{
			std::cout << "Localização na Hash Table: " << i << std::endl;
			for ( auto it = pos->begin(); it != pos->end(); ++it)
			{
				std::cout << "( " << it->m_key.first << ", " << it->m_key.second << " )"
				<< ", " << it->m_data << std::endl;
			}
			std::cout << std::endl;
		}
	}
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
void HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::print3() const
{
	for ( unsigned int i = 0; i < m_size; ++i)
	{
		auto pos = (m_data_table+i);
		if ( not pos->empty())
		{
			std::cout << "Localização na Hash Table: " << i << std::endl;
			for ( auto it = pos->begin(); it != pos->end(); ++it)
			{
				std::cout << "( " << std::get<0>(it->m_key) << ", "
								  << std::get<1>(it->m_key) << ", "
								  << std::get<2>(it->m_key) << ", "
								  << std::get<3>(it->m_key) << " )"
				 << ", " << it->m_data << std::endl;
			}
			std::cout << std::endl;
		}
	}
}

template< class KeyType, class DataType, class KeyHash, class KeyEqual >
void HashTbl< KeyType, DataType, KeyHash, KeyEqual >
::rehash()
{
	auto backup = m_data_table;
	auto old_size = m_size;

	auto primo = 2*m_size+1;

	bool eh_primo = false;
	while ( eh_primo != true )
	{
		if (primo % 2)
		{
			eh_primo = false;
			++primo;
			continue;
		}
		for ( unsigned int i = 3; i < primo/2; i+=2 )
		{
			if ( primo % i )
			{
				eh_primo = false;
				++primo;
			}
		}
		eh_primo = true;
	}
	m_size = primo;
	m_count = 0;
	m_data_table = new std::list< Entry >[m_size];

	for ( unsigned int i = 0; i < old_size; ++i)
	{
		auto pos = (backup+i);
		if ( not pos->empty())
		{
			for ( auto it = pos->begin(); it != pos->end(); ++it)
			{
				insert( it->m_key, it->m_data );
			}
			pos->clear();
		}
	}
	delete[] backup;
}

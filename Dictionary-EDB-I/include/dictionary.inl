/**
 * @file dictionary.inl
 * @brief      Implementação dos métodos das classes DAL e DSAL.
 * @details    
 *
 * @author     João Vítor Venceslau Coelho
 * @since      05/12/2017
 * @date       07/12/2017
 */

// DAL

template <typename Key, typename Data, typename KeyComparator>
int DAL<Key, Data, KeyComparator>::_search ( const Key & _x ) const 
{
	KeyComparator func_comp;
	Key key_test;

	for ( int i = 0; i < mi_length; ++i)
	{
		key_test = mpt_data[i].id;
		if ( not func_comp(key_test, _x) and not func_comp(_x, key_test)  )
		{
			return i;
		}
	}
	return -1;
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::remove ( const Key & _x, Data & _s )
{
	if ( empty() )
	{
		return false;
	}
	auto posicao = _search( _x );

	if ( posicao == (mi_length-1))
	{
		_s = mpt_data[posicao].info;
		--mi_length;
		return true;

	}
	else if ( posicao != -1 )
	{
		_s = mpt_data[posicao].info;
		mpt_data[posicao] = mpt_data[mi_length-1];
		--mi_length;
		return true;
	}

	return false;

}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::search ( const Key & _x, Data & _s ) const
{
	if ( empty() )
	{
		return false;
	}

	auto posicao = _search( _x );

	if ( posicao != -1 )
	{
		_s = mpt_data[posicao].info;
		return true;
	}

	return false;
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::insert ( const Key & _newKey , const Data & _newInfo )
{
	if ( mi_length == mi_capacity )
	{
		return false;
	}

	for (int i = 0; i < mi_length; ++i)
	{
		if ( mpt_data[i].id == _newKey ) //and mpt_data[i].info == _newInfo)
		{
			return false;
		}
	}

	mpt_data[mi_length].id = _newKey;
	mpt_data[mi_length].info = _newInfo;
	++mi_length;

	return true;
}

template <typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::min ( ) const
{
	if ( empty() )
	{
		throw std::out_of_range("min(): Dicionário vazio.");
	}

	KeyComparator func_comp;
	Key key_test = mpt_data[0].id;

	for (int i = 1; i < mi_length; ++i)
	{
		if ( func_comp( mpt_data[i].id, key_test ) )
		{
			key_test = mpt_data[i].id;
		}
	}

	return key_test;

}

template <typename Key, typename Data, typename KeyComparator>
Key DAL<Key, Data, KeyComparator>::max ( ) const
{
	if ( empty() )
	{
		throw std::out_of_range("max(): Dicionário vazio.");
	}

	KeyComparator func_comp;
	Key key_test = mpt_data[0].id;

	for (int i = 0; i < mi_length; ++i)
	{
		if ( func_comp( key_test, mpt_data[i].id ) )
		{
			key_test = mpt_data[i].id;
		}
	}

	return key_test;
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::sucessor ( const Key & _x , Key & _y ) const
{
	if ( empty() or _search( _x ) == -1 )
	{
		return false;
	}

	KeyComparator func_comp;
	Key sucessor = max();
	Key aux;

	for ( int i = 0; i < mi_length; ++i )
	{
		aux = mpt_data[i].id;
		if ( func_comp(_x, aux ) and ( func_comp(aux, sucessor) ))
		{
			sucessor = aux; 
		}
	}

	if ( not func_comp(sucessor, _x) and not func_comp(_x, sucessor)  )
	{
		return false;
	}
	else
	{
		_y = sucessor;
		return true;
	}
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::predecessor ( const Key & _x , Key & _y ) const 
{
	if ( empty() or _search( _x ) == -1 )
	{
		return false;
	}

	KeyComparator func_comp;
	Key predecessor = min();
	Key aux;

	for ( int i = 0; i < mi_length; ++i )
	{
		aux = mpt_data[i].id;
		if ( func_comp( aux, _x ) and ( func_comp( predecessor, aux ) ))
		{
			predecessor = aux; 
		}
	}

	if ( not func_comp(predecessor, _x) and not func_comp(_x, predecessor)  )
	{
		return false;
	}
	else
	{
		_y = predecessor;
		return true;
	}
}

template <typename Key, typename Data, typename KeyComparator>
int DAL<Key, Data, KeyComparator>::capacity ( ) const 
{
	return mi_capacity;
}

template <typename Key, typename Data, typename KeyComparator>
bool DAL<Key, Data, KeyComparator>::empty ( ) const 
{
	return mi_length == 0;
}


// DSAL

template <typename Key, typename Data, typename KeyComparator>
int DSAL<Key, Data, KeyComparator>::_search ( const Key & _x ) const
{
	int first = 0;
	int last = this->mi_length-1;

	KeyComparator func_comp;

	while ( first <= last )
	{
		int mid = (first + last)/2;
		Key key_test = this->mpt_data[mid].id;

		if ( ( not func_comp(_x, key_test)) and ( not func_comp(key_test, _x)) )
		{
			return mid;
		}
		else if ( func_comp(_x, key_test) )
		{
			last = mid-1;
		}
		else
		{	
			first = mid+1;
		}
	}
	return -1;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::remove ( const Key & _x, Data & _s )
{
	if ( this->empty() )
	{
		return false;
	}
	
	auto posicao = _search( _x );

	if ( posicao == (this->mi_length-1) )
	{
		_s = this->mpt_data[posicao].info;
		--(this->mi_length);
		return true;

	}
	else if ( posicao != -1 )
	{
		_s = this->mpt_data[posicao].info;
		std::copy( &(this->mpt_data[posicao+1]), &(this->mpt_data[this->mi_length+1]), &(this->mpt_data[posicao]) );
		--(this->mi_length);
		return true;
	}
	return false;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::insert ( const Key & _newKey , const Data & _newInfo )
{
	if ( this->mi_length == this->mi_capacity or _search(_newKey) != -1)
	{
		return false;
	}

	KeyComparator func_comp;
	Key aux;

	int possible_pos= 0;
	int posicao = -1;

	while ( possible_pos < this->mi_length )
	{
		aux = this->mpt_data[possible_pos].id;
		if ( func_comp( aux, _newKey) )
		{
			posicao = possible_pos;
		}
		++possible_pos;
	}

	if ( posicao == this->mi_length-1 )
	{
		this->mpt_data[this->mi_length].id = _newKey;
		this->mpt_data[this->mi_length].info = _newInfo;
		++(this->mi_length);
		return true;
	}
	else if ( posicao == -1)
	{
		for ( int i = this->mi_length; i > posicao+1; --i)
		{
			this->mpt_data[i].id = this->mpt_data[i-1].id;
			this->mpt_data[i].info = this->mpt_data[i-1].info;
		}
		this->mpt_data[0].id = _newKey;
		this->mpt_data[0].info = _newInfo;
		++(this->mi_length);
		return true;
	}
	else
	{
		for ( int i = this->mi_length; i > posicao+1; --i)
		{
			this->mpt_data[i].id = this->mpt_data[i-1].id;
			this->mpt_data[i].info = this->mpt_data[i-1].info;
		}
		this->mpt_data[posicao+1].id = _newKey;
		this->mpt_data[posicao+1].info = _newInfo;
		++(this->mi_length);
		return true;
	}
	
	return false;
}

template <typename Key, typename Data, typename KeyComparator>
Key DSAL<Key, Data, KeyComparator>::min ( ) const
{
	if ( this->empty() )
	{
		throw std::out_of_range("min(): Dicionário vazio.");
	}

	return this->mpt_data[0].id;
}

template <typename Key, typename Data, typename KeyComparator>
Key DSAL<Key, Data, KeyComparator>::max ( ) const 
{
	if ( this->empty() )
	{
		throw std::out_of_range("max(): Dicionário vazio.");
	}
	return this->mpt_data[(this->mi_length)-1].id;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::sucessor ( const Key & _x , Key & _y ) const
{
	auto posicao = _search(_x);

	if ( posicao == -1 or posicao == this->mi_length-1 or this->empty() )
	{
		return false;
	}
	
	_y = this->mpt_data[posicao+1].id;

	return true;
}

template <typename Key, typename Data, typename KeyComparator>
bool DSAL<Key, Data, KeyComparator>::predecessor ( const Key & _x , Key & _y ) const
{
	auto posicao = _search(_x);

	if ( posicao == -1 or posicao == 0 or this->empty() )
	{
		return false;
	}
	
	_y = this->mpt_data[posicao-1].id;
	
	return true;
}
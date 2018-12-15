/**
 * @file dictionary.hpp
 * @brief      Declaração dos métodos e atributos das classes DAL e DSAL.
 * @details    
 *
 * @author     João Vítor Venceslau Coelho
 * @since      05/12/2017
 * @date       07/12/2017
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>

/**
 * @brief      Classe para um Dicionário com Vetor não Ordenado
 *
 * @tparam     Key            Tipo da Chave
 * @tparam     Data           Tipo dos elementos associados a cada Chave
 * @tparam     KeyComparator  Functor para a comparação
 */
template <typename Key, typename Data, typename KeyComparator = std::less<Key> >
class DAL
{
protected:
	/**
	 * @brief      Struct que representa o par Chave-Informação
	 */
	struct NodeAL {
		Key id;
		Data info;
	};

	const static int SIZE = 50;
	int mi_length;
	int mi_capacity;
	NodeAL * mpt_data;

	/**
	* @brief      Busca um elemento pela chave a ele associada
	 *
	 * @param[in]  _x   A Chave do elemento a ser buscado
	 *
	 * @return     Posição do elemento no dicionário
	 */
	int _search ( const Key & _x ) const;
	
public:

	/**
	 * @brief      Construtor da Classe DAL
	 *
	 * @param[in]  _MaxSz  Tamanho máximo do DAL
	 */
	DAL ( int _MaxSz = SIZE )
		: mi_length(0)
		, mi_capacity( _MaxSz )
		, mpt_data ( new NodeAL[ _MaxSz ] )
	{ /* Vazio */ }

	/**
	 * @brief      Destrutor do DAL
	 */
	virtual ~DAL() { delete[] mpt_data; };

	/**
	 * @brief      Elimina o elemento associado a chave informada do dicionario,
	 *             mas guarda os dados no campo indicado
	 *
	 * @param[in]  _x    Chave do elemento a ser removido
	 * @param      _s    Dados recuperados do elemento removido, caso tenha sido removido
	 *
	 * @return     True se foi devidamento removido, false caso contrário
	 */
	bool remove ( const Key & _x, Data & _s ); 

	/**
	 * @brief      Busca um elemento pela chave a ele associada
	 *
	 * @param[in]  _x    A Chave do elemento a ser buscado
	 * @param      _s    Local onde os dados seram guardados caso a busca seja bem sucedida
	 *
	 * @return     True se a busca foi bem sucedida, false caso contrário
	 */
	bool search ( const Key & _x , Data & _s ) const; 

	/**
	 * @brief      Insere no dicionario o par chave, dados informado
	 *
	 * @param[in]  _newKey   Chave associada ao elemento a ser inserido
	 * @param[in]  _newInfo  Dados do elemento a ser inserido
	 *
	 * @return     True se foi inserido, false otherwise
	 */
	bool insert ( const Key & _newKey , const Data & _newInfo );

	/**
	 * @brief      Recupera a menor Chave armazenada
	 *
	 * @return     A menor chave armazenada ou lança a exceção std::out_of_range
	 *             se estiver vazio
	 */
	Key min ( ) const;

	/**
	 * @brief      Recupera a maior Chave armazenada
	 *
	 * @return     A maior chave armazenada ou lança a exceção std::out_of_range
	 *             se estiver vazio
	 */
	Key max ( ) const;

	/**
	 * @brief      Encontra a chave que sucede a chave indicada, se ela existir
	 *
	 * @param[in]  _x    A chave cujo sucessor será buscado
	 * @param      _y    Local onde a chave sucessora deve ser copiada se encontrada
	 *
	 * @return     true se foi o sucessor foi encontrado, false caso contrário
	 */
	bool sucessor ( const Key & _x , Key & _y ) const;

	/**
	 * @brief      Encontra a chave que precede a chave indicada, se ela existir
	 *
	 * @param[in]  _x    A chave cujo predecessor será buscado
	 * @param      _y    Local onde a chave predecessora deve ser copiada se encontrada
	 *
	 * @return     true se foi o predecessor foi encontrado, false caso contrário
	 */
	bool predecessor ( const Key & _x , Key & _y ) const;

	/**
	 * @brief      Sobrecarga do operador <<
	 *
	 * @param      _os     O ostream onde as chaves e seus elementos associados serão impressos
	 * @param[in]  _oList  Dicionário alvo
	 *
	 * @return     Ostream com os dados já formatados
	 */
	inline friend std::ostream & operator << ( std::ostream & _os , const DAL & _oList ) 
	{
		_os << "[ ";
		for ( int i(0); i < _oList.mi_length; ++i )
			_os << "{ id: " << _oList.mpt_data[ i ].id << ", info: "
				<< _oList.mpt_data[ i ].info << " } ";
			_os << " ] " ;
	
		return _os;
	}

	/**
	 * @brief      Verifica qual é a capacidade do Dicionário
	 *             
	 * @return     A capacidade do Dicionário
	 */
	int capacity ( ) const;

	/**
	 * @brief      Verifica se o Dicionário está vazio
	 *
	 * @return     true se está vazio, false caso contrário
	 */
	bool empty ( ) const;
};

/**
 * @brief      Classe para um Dicionário com Vetor Ordenado
 *
 * @tparam     Key            Tipo da Chave
 * @tparam     Data           Tipo dos elementos associados a cada Chave
 * @tparam     KeyComparator  Functor para a comparação
 */
template <typename Key, typename Data, typename KeyComparator = std::less<Key> >
class DSAL: public DAL<Key, Data, KeyComparator >
{
private:

	const static int SIZE = 50;

	/**
	* @brief      Busca um elemento pela chave a ele associada
	 *
	 * @param[in]  _x   A Chave do elemento a ser buscado
	 *
	 * @return     Posição do elemento no dicionário
	 */
	int _search ( const Key & _x ) const;

public:

	/**
	 * @brief      Construtor da Classe DSAL
	 *
	 * @param[in]  _MaxSz  Tamanho máximo do DSAL
	 */
	DSAL ( int _MaxSz = SIZE ) : DAL<Key, Data, KeyComparator>( _MaxSz ) { /* Vazio */ };

	/**
	 * @brief      Destrutor do DAL
	 */
	virtual ~DSAL () { /* Vazio */ };

	/**
	 * @brief      Elimina o elemento associado a chave informada do dicionario,
	 *             mas guarda os dados no campo indicado
	 *
	 * @param[in]  _x    Chave do elemento a ser removido
	 * @param      _s    Dados recuperados do elemento removido, caso tenha sido removido
	 *
	 * @return     True se foi devidamento removido, false caso contrário
	 */
	bool remove ( const Key & _x, Data & _s ); 

	/**
	 * @brief      Insere no dicionario o par chave, dados informado
	 *
	 * @param[in]  _newKey   Chave associada ao elemento a ser inserido
	 * @param[in]  _newInfo  Dados do elemento a ser inserido
	 *
	 * @return     True se foi inserido, false otherwise
	 */
	bool insert ( const Key & _newKey , const Data & _newInfo );

	/**
	 * @brief      Recupera a menor Chave armazenada
	 *
	 * @return     A menor chave armazenada ou lança a exceção std::out_of_range
	 *             se estiver vazio
	 */
	Key min ( ) const;

	/**
	 * @brief      Recupera a maior Chave armazenada
	 *
	 * @return     A maior chave armazenada ou lança a exceção std::out_of_range
	 *             se estiver vazio
	 */
	Key max ( ) const;

	/**
	 * @brief      Encontra a chave que sucede a chave indicada, se ela existir
	 *
	 * @param[in]  _x    A chave cujo sucessor será buscado
	 * @param      _y    Local onde a chave sucessora deve ser copiada se encontrada
	 *
	 * @return     true se foi o sucessor foi encontrado, false caso contrário
	 */
	bool sucessor ( const Key & _x , Key & _y ) const;

	/**
	 * @brief      Encontra a chave que precede a chave indicada, se ela existir
	 *
	 * @param[in]  _x    A chave cujo predecessor será buscado
	 * @param      _y    Local onde a chave predecessora deve ser copiada se encontrada
	 *
	 * @return     true se foi o predecessor foi encontrado, false caso contrário
	 */
	bool predecessor ( const Key & _x , Key & _y ) const;
};

#include "dictionary.inl"

#endif
/**
 * @file hashtbl.hpp
 * @brief      Declaração dos atributos e métodos da classe HashTbl
 * @details    { detailed_item_description }
 *
 * @author     João Vítor Venceslau Coelho / Selan Rodrigues dos Santos
 * @since      02/12/2017
 * @date       05/12/2017
 */

#ifndef _HASHTBL_H_
#define _HASHTBL_H_

#include <iostream>
#include <list>

namespace ac {

	/**
	 * @brief      Classe para HashEntry
	 *
	 * @tparam     KeyType   Tipo da Chave
	 * @tparam     DataType  Tipo do dado a ser armazenado
	 */
	template< class KeyType, class DataType >
	class HashEntry
	{
		public:

			KeyType m_key;  // Armazena a chave associada a informcao
			DataType m_data;// A informacao.

			/**
			 * @brief      Construtor da HashEntry
			 *
			 * @param[in]  kt_   Chave associada ao dado informado
			 * @param[in]  dt_   Dado associado à chave informada
			 */
			HashEntry( KeyType kt_, DataType dt_ ) : m_key(kt_), m_data(dt_)
			{/*Empty*/}
			
			/**
			 * @brief      Sobrecarga do operador de <<
			 *
			 * @param      _os   O ostream onde serão impressos os dados
			 * @param[in]  _he   A HashEntry que contem os dados
			 *
			 * @return     Ostream com os dados já formatados
			 */
			inline friend std::ostream &operator<< ( std::ostream & _os, const HashEntry & _he )
			{
				_os << _he.m_data << std::endl;
				 return _os;
			}
	};

	/**
	 * @brief      Classe para uma Hash Table
	 *
	 * @tparam     KeyType   Tipo da Chave
	 * @tparam     DataType  Tipo do dado a ser armazenado
	 * @tparam     KeyHash   Função de Hash a ser utilizada
	 * @tparam     KeyEqual  Função de Comparação a ser utilizada
	 */
	template< class KeyType,
			  class DataType,
			  class KeyHash = std::hash < KeyType > ,
			  class KeyEqual = std::equal_to < KeyType > >
	class HashTbl
	{
		public:
			typedef HashEntry<KeyType,DataType> Entry;

			/**
			 * @brief      Construtor da Hash Table
			 *
			 * @param[in]  TableSz_  Tamanho inicial da Hash Table
			 */
			HashTbl( int TableSz_ = DEFAULT_SIZE );

			/**
			 * @brief      Destrutor da Hash Table
			 */
			virtual ~HashTbl();

			/**
			 * @brief      Insere um novo elemento na Hash Talbe
			 *
			 * @param[in]  k_    Chave associada ao elemento a ser inserido
			 * @param[in]  d_    Dados do elemento a ser inserido
			 *
			 * @return     True se o elemento foi inserido com sucesso, false se
			 *             já existia um elemento associado a essa chave, (
			 *             elemento antigo foi sobrescrito )
			 */
			bool insert( const KeyType & k_, const DataType & d_ );

			
			/**
			 * @brief      Remove da Hash Table o elemento associado com a chave
			 *             indicada
			 *
			 * @param[in]  k_    Chave do elemento a ser buscado
			 *
			 * @return     True se o elemento foi devidamente removido, false caso contrário
			 */
			bool remove( const KeyType & k_ );
			
			/**
			 * @brief      Recupera os dados associados à chave indicada (k_) e
			 *             os salva na variável d_
			 *
			 * @param[in]  k_    Chave do elemento a ser buscado
			 * @param      d_    Variável que deve armazenar o valor associado à
			 *                   chave, caso encontrado
			 *
			 * @return     True se o elemento foi encontrado, false caso contrário
			 */
			bool retrieve( const KeyType & k_, DataType & d_ ) const;
			
			/**
			 * @brief      Apaga todos os elementos da Hash Table
			 */
			void clear( void );
			
			/**
			 * @brief      Verifica se a Hash Table está vazia
			 *
			 * @return     True se está vazia, false caso contrário
			 */
			bool empty( void ) const;
			
			/**
			 * @brief      Informa a quantidad de elementos armazenados na Hash
			 *             Table
			 *
			 * @return     Número de elementos da Hash Table
			 */
			unsigned int count() const { return m_count; }
			
			/**
			 * @brief      Informa o tamanho máximo da Hash Table
			 *
			 * @return     Tamanho da Hash Table
			 */
			unsigned int size() const { return m_size; }
			
			/**
			 * @brief      Função simples que imprime o par (chave, dados)
			 */
			void print1() const; // Para debugs
			
			/**
			 * @brief      Função simples que imprime o par (chave, dados)
			 *             devidamente formatados para pares ordenados ( pair )
			 */
			void print2() const;
			
			/**
			 * @brief      Função simples que imprime o par (chave, dados)
			 *             devidamente formatados para tuplas ( tuples )
			 */
			void print3() const;

			/**
			 * @brief      Sobrecarga do operador de <<
			 *
			 * @param      _os   O ostream onde serão impressos os dados
			 * @param[in]  _ht   A hashtable que contem os dados
			 *
			 * @return     Ostream com os dados já formatados
			 */
			inline friend std::ostream &operator<< ( std::ostream & _os, const HashTbl & _ht )
			{		
				for ( unsigned int i = 0; i < _ht.m_size; ++i)
				{
					auto pos = (_ht.m_data_table+i);
					if ( not pos->empty())
					{
						std::cout << "Localização na Hash Table: " << i << std::endl;
						for ( auto it = pos->begin(); it != pos->end(); ++it)
						{
							_os << *it;	
						}
					}
				}
				return _os;
			}

		private:
			
			/**
			 * @brief      Função que após dobrar a capacidade da tabela,
			 *             posiciona os elementos já armazenados em suas novas
			 *             posições de acordo com a função has atualizada
			 */
			void rehash();        //!< Change Hash table size if load factor >1.0
			
			unsigned int m_size;  //!< Tamanho da tabela.
			
			unsigned int m_count; //!< Numero de elementos na tabel. 
			
			std::list< Entry > *m_data_table; //!< Tabela de listas para entradas de tabela.
			
			static const short DEFAULT_SIZE = 11;
	};

} // MyHashTable
#include "hashtbl.inl"
#endif












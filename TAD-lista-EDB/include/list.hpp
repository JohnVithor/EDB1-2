/**
* @file		list.hpp
* @brief	Definição da classe ls::list
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/11/2017
* @date		25/11/2017	
*/

#ifndef	LIST_H
#define LIST_H

#include <initializer_list>
#include <stdexcept>

namespace ls
{
	using size_type = unsigned long;

	/**
	 * @brief      Classe que implementa uma Lista Duplamente Encadeada
	 *
	 * @tparam     T     Tipo dos elementos da lista
	 */
	template < typename T >
	class list
	{
	private:

		/**
		 * @brief      Struct que simboliza um Nó da Lista
		 */
		struct Node
		{
			T data;			//<! Data field

			Node *prev;		//<! Pointer to the previous node in the list.

			Node *next;		//<! Pointer to the next node in the list.
			
			/**
			 * @brief      Construtor do Node
			 *
			 * @param[in]  d     Conteúdo do Node
			 * @param      p     Node posterior
			 * @param      n     Node anteior
			 */
			Node( const T & d = T( ), Node * p = nullptr, Node * n = nullptr )
				: data( d ), prev(p), next( n )
			{ /* Empty */ }
		};
	public:
		
		/**
		 * @brief      Classe para Iterador Constante
		 */
		class const_iterator
		{
		public:

			/**
			 * @brief      Construtor padrão do iterador constante
			 */
			const_iterator( ) = default;
			
			/**
			 * @brief      Sobrecarga do operador *
			 *
			 * @return     Referência constante para o conteúdo do Node apontado
			 *             pelo iterador constante
			 */
			const T & operator* () const;
			
			/**
			 * @brief      Sobrecarga do operador ++ ( pré-incremento )
			 *
			 * @return     Iterador constante para o Node posterior
			 */
			const_iterator & operator++ ( );	// ++it;
			
			/**
			 * @brief      Sobrecarga do operador ++ ( pos-incremento )
			 *
			 * @return     Iterador constante para o Node posterior
			 */
			const_iterator operator++ ( int );	// it++;
			
			/**
			 * @brief      Sobrecarga do operador -- ( pré-decremento )
			 *
			 * @return     Iterador constante para o Node anterior
			 */
			const_iterator & operator-- ( );	// --it;
			
			/**
			 * @brief      Sobrecarga do operador -- ( pos-decremento )
			 *
			 * @return     Iterador constante para o Node anterior
			 */
			const_iterator operator-- ( int );	// it--;
			
			/**
			 * @brief      Sobrecarga do operador +
			 *
			 * @param[in]  num   O número de avanços que o iterador deve
			 *                   realizar
			 *
			 * @return     Iterador constante para o Node num posições a frente
			 */
			const_iterator operator+ ( size_type num );
			
			/**
			 * @brief      Sobrecarga do operador -
			 *
			 * @param[in]  num   O número de recuos que o iterador deve realizar
			 *
			 * @return     Iterador constante para o Node num posições atrás
			 */
			const_iterator operator- ( size_type num );
			
			/**
			 * @brief      Sobrecarga do operador ==
			 *
			 * @param[in]  rhs   Iterador a ser comparado
			 *
			 * @return     True se os dois são iguais, False caso contrário
			 */
			bool operator== ( const const_iterator & rhs ) const;
			
			/**
			 * @brief      Sobrecarga do operador !=
			 *
			 * @param[in]  rhs   Iterador a ser comparado
			 *
			 * @return     True se os dois são diferentes, False caso contrário
			 */
			bool operator!= ( const const_iterator & rhs ) const;
					
		protected:

			Node *current;

			/**
			 * @brief      Construtor do Iterador Constante a partir de um
			 *             ponteiro para Node
			 *
			 * @param      p     Ponteiro para o Node
			 */
			const_iterator( Node * p ) : current( p ) { /* Empty */ }

			friend class list<T>;
		};

		/**
		 * @brief      Classe para Iterador.
		 */
		class iterator : public const_iterator
		{
		public:
			
			/**
			 * @brief      { function_description }
			 */
			iterator( )	: const_iterator( )	{ /* Empty */ }
			
			/**
			 * @brief      Sobrecarga do operador *
			 *
			 * @return     Referência constante para o conteúdo do Node apontado
			 *             pelo iterador
			 */
			const T & operator* ( ) const;
			
			/**
			 * @brief      Sobrecarga do operador *
			 *
			 * @return     Referência para o conteúdo do Node apontado pelo
			 *             iterador
			 */
			T & operator* ( );
			
			/**
			 * @brief      Sobrecarga do operador ++ ( pré-incremento )
			 *
			 * @return     Iterador para o Node posterior
			 */
			iterator & operator++ ( );		// ++it;
			
			/**
			 * @brief      Sobrecarga do operador ++ ( pos-incremento )
			 *
			 * @return     Iterador para o Node posterior
			 */
			iterator operator++ ( int );	// it++;
			
			/**
			 * @brief      Sobrecarga do operador -- ( pré-decremento )
			 *
			 * @return     Iterador para o Node anterior
			 */
			iterator & operator-- ( );		// --it;
			
			/**
			 * @brief      Sobrecarga do operador -- ( pos-decremento )
			 *
			 * @return     Iterador para o Node anterior
			 */
			iterator operator-- ( int );	// it--;

		protected:

			/**
			 * @brief      Construtor do Iterador a partir de um ponteiro para
			 *             Node
			 *
			 * @param      p     Ponteiro para o Node
			 */
			iterator( Node *p ) : const_iterator( p ) { /* Empty */ }

			friend class list<T>;
		};

		// [I] SPECIAL MEMBERS

		/**
		 * @brief      Construtor Vazio da lista
		 */
		list();
		
		/**
		 * @brief      Construtor com número inicial de Nodes
		 *
		 * @param[in]  count  O número de Nodes
		 */
		explicit list( size_type count );
		
		/**
		 * @brief      Construtor da lista a partir dos elementos de um
		 *             intervalo [ First, Last )
		 *
		 * @param[in]  first    Inicio do intervalo
		 * @param[in]  last     Fim do intervalo
		 *
		 * @tparam     InputIt  Tipo das variáveis que indicam o intervalo
		 */
		template< typename InputIt >		
		list( InputIt first, InputIt last );
		
		/**
		 * @brief      Construtor cópia da lista
		 *
		 * @param[in]  other  Lista a ser copiada
		 */
		list( const list& other );
		
		/**
		 * @brief      Construtor da lista a partir de uma lista inicializadora
		 *
		 * @param[in]  ilist  A lista inicializadora
		 */
		list( std::initializer_list<T> ilist );
		
		/**
		 * @brief      Destrutor da lista
		 */
		~list();
		
		/**
		 * @brief      Sobrecarga do operador =
		 *
		 * @param[in]  other  Lista a ser atribuida
		 *
		 * @return     Nova lista
		 */
		list & operator=( const list& other );
		
		/**
		 * @brief      Sobrecarga do operador =
		 *
		 * @param[in]  ilist  Lista inicializadora a ser atribuida
		 *
		 * @return     Nova lista
		 */
		list & operator=( std::initializer_list<T> ilist );

		// [II] ITERATORS

		/**
		 * @brief      Cria e retorna um iterador a partir do endereço do
		 *             primeiro elemento da lista
		 *
		 * @return     Iterador para o primeiro elemento da lista
		 */
		iterator begin( );

		/**
		 * @brief      Cria e retorna um iterador constante a partir do endereço
		 *             do primeiro elemento da lista
		 *
		 * @return     Iterador constante para o primeiro elemento da lista
		 */
		const_iterator cbegin( ) const;

		/**
		 * @brief      Cria e retorna um iterador a partir do endereço do ultimo
		 *             elemento da lista
		 *
		 * @return     Iterador para o ultimo elemento da lista
		 */
		iterator end( );

		/**
		 * @brief      Cria e retorna um iterador constante a partir do endereço
		 *             do ultimo elemento da lista
		 *
		 * @return     Iterador constante para o ultimo elemento da lista
		 */
		const_iterator cend( ) const;

		// [III] Capacity
		
		/**
		 * @brief      Acessa e retorna o tamanho lógico da lista
		 *
		 * @return     Tamanho lógico da lista
		 */
		size_type size( ) const;
		
		/**
		 * @brief      Verifica se a lista possui algum elemento, isto é o
		 *             tamanho lógico é 0
		 *
		 * @return     True se ele está vazio, False caso não esteja
		 */
		bool empty( ) const;

		// [IV] Modifiers
		
		/**
		 * @brief      Zera o numero de elementos da lista
		 */
		void clear( );
		
		/**
		 * @brief      Acessa o primeiro elemento da lista
		 *
		 * @return     Retorna uma referencia para o primeiro elemento da lista
		 */
		T & front( );
		
		/**
		 * @brief      Acessa o primeiro elemento da lista
		 *
		 * @return     Retorna uma referencia constante para o primeiro elemento
		 *             da lista
		 */
		const T & front( ) const;
		
		/**
		 * @brief      Acessa o ultimo elemento da lista
		 *
		 * @return     Retorna uma referencia para o ultimo elemento da lista
		 */
		T & back( );
		
		/**
		 * @brief      Acessa o ultimo elemento da lista
		 *
		 * @return     Retorna uma referencia constante para o ultimo elemento
		 *             da lista
		 */
		const T & back( ) const;
		
		/**
		 * @brief      Adiciona o elemento indicado ao inicio da lista
		 *
		 * @param[in]  value  Valor a ser adicionado
		 */
		void push_front( const T & value );
		
		/**
		 * @brief      Adiciona o elemento indicado ao fim da lista
		 *
		 * @param[in]  value  Valor a ser adicionado
		 */
		void push_back( const T & value );
		
		/**
		 * @brief      Elimina o primeiro elemento da lista
		 */
		void pop_front( );
		
		/**
		 * @brief      Elimina o ultimo elemento da lista
		 */
		void pop_back( );
		
		/**
		 * @brief      Substitui todos os elementos da lista pelo elemento
		 *             indicado
		 *
		 * @param[in]  value  Elemento a ser utilizado nas substituições
		 */
		void assign( const T& value );

		// Operator overloading
		
		/**
		 * @brief      Sobrecarga do operador == para comparar listas
		 *
		 * @param[in]  other  Lista a ser comparada
		 *
		 * @return     True se as listas são iguais, False caso contrário
		 */
		bool operator==( const list& other );
		
		/**
		 * @brief      Sobrecarga do operador != para comparar listas
		 *
		 * @param[in]  other  Lista a ser comparada
		 *
		 * @return     True se as listas são diferentes, False caso contrário
		 */
		bool operator!=( const list& other );

		// [IV-a] Modifiers with iterators
		
		/**
		 * @brief      Substitui todos os elementos da lista por n count copias
		 *             do valor indicado
		 *
		 * @param[in]  count  O número de copias
		 * @param[in]  value  O valor a ser atribuido
		 */
		void assign( size_type count, const T& value );

		/**
		 * @brief      Substitui todos os elementos da lista pelos do intervalo
		 *             indicado
		 * @details    Se o fim do intervalo for alcançado, os proximos
		 *             elementos da lista serão substituidos pela lista
		 *             novamente, de maneira repetitiva até a lista ficar
		 *             completa
		 *
		 * @param[in]  first  Inicio do intervalo
		 * @param[in]  last   Fim do intervalo
		 *
		 * @tparam     InItr  Tipo das variáveis que indicam o intervalo
		 */
		template < typename InItr >
		void assign( InItr first, InItr last );
		
		/**
		 * @brief      Substitui todos os elementos da lista pelos elementos da
		 *             lista inicializadora
		 *
		 * @param[in]  ilist  Lista inicializadora a ser utilizada
		 */
		void assign( std::initializer_list<T> ilist );
		
		/**
		 * @brief      Insere o elemento indicado na posição indicada pelo
		 *             iterador
		 *
		 * @param[in]  itr    Iterador que indica a posição
		 * @param[in]  value  Elemento a ser inserido
		 *
		 * @return     Iterador que indica a posição do elemento inserido ( a
		 *             mesma que foi passada )
		 */
		iterator insert( const_iterator itr, const T & value );
		
		/**
		 * @brief      Insere todos os elementos indicados do intervalo indicado
		 *             na lista a partir posição indicada pelo iterador
		 *
		 * @param[in]  pos       Iterador que indica a posição inicial
		 * @param[in]  first     Inicio do intevalo indicado
		 * @param[in]  last      Fim do intevalo indicado
		 *
		 * @tparam     InputItr  { description }
		 * @tparam     Tipo  das variáveis que indicam o intervalo
		 *
		 * @return     Iterador que indica a posição do ultimo elemento
		 *             inserido
		 */
		template < typename InputItr >
		iterator insert ( const_iterator pos, InputItr first, InputItr last);
		
		/**
		 * @brief      Insere todos da lista inicializadora indicada na lista a
		 *             partir posição indicada pelo iterador
		 *
		 * @param[in]  pos    Iterador que indica a posição inicial
		 * @param[in]  ilist  Lista inicializadora
		 *
		 * @return     Iterador que indica a posição do ultimo elemento inserido
		 */
		iterator insert( const_iterator pos, std::initializer_list<T> ilist );
		
		/**
		 * @brief      Retira da lista o elemento da itrtição indicada
		 *
		 * @param[in]  itr   Iterador para a posição do elemento a ser retirado
		 *
		 * @return     Retorna um iterador para a ultima posição válida da lista
		 */
		iterator erase( const_iterator itr );
		
		/**
		 * @brief      Retira da lista os elementos no intervalo indicado
		 *
		 * @param[in]  first  Inicio do intervalo
		 * @param[in]  last   Fim do intervalo
		 *
		 * @return     Retorna um iterador para a ultima posição válida da lista
		 */
		iterator erase( const_iterator first, const_iterator last );
		
		/**
		 * @brief      Procura pelo primeiro Node que guarda o valor indicado
		 *
		 * @param[in]  value  O valor a ser buscado
		 *
		 * @return     Iterador constante para o Node encontrado, ou para o tail
		 *             caso o valor não tenha sido encontrado
		 */
		const_iterator find( const T & value ) const;

	private:

		Node *m_head;
		
		Node *m_tail;		

		size_type m_size;

	};
}

#include "iterators.inl"
#include "list.inl"

#endif
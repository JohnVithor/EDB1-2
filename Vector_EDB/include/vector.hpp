/**
* @file		vector.hpp
* @brief	Definição das classes sc::MyIterator e sc::vector, seus atributos e métodos
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/10/2017
* @date		21/10/2017	
*/

#ifndef	VECTOR_H
#define VECTOR_H

#include <memory>
#include <initializer_list>

#include <iostream> 	//std::cout 
#include <string> 		//std::string
#include <iterator> 
#include <stdexcept> 	// out_of_range
#include <cassert> 		//assert
#include <algorithm> 	//std::copy

namespace sc
{
	/**
	* @brief Um tipo simplificado de iterador
	* @tparam T Tipo do valor que será utilizado para o template do iterador
	*/
	template < typename T >
	class MyIterator
	{
		public:
			typedef T value_type;
			typedef std::size_t size_type;
			typedef MyIterator self_type;
			typedef std::ptrdiff_t difference_type;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef std::random_access_iterator_tag iterator_category;

		private:
			pointer m_ptr;

		public:
			/**
			* @brief Construtor da classe MyIterator. Inicia o ponteiro interno
			* @param[in] ptr Ponteiro interno
			*/
			MyIterator( pointer ptr = nullptr );

			/**
			* @brief Destrutor da classe MyIterator.
			*/
			~MyIterator() = default;

			/**
			* @brief Sobrecarga do operador ++ de pré-incremento
			* @return Iterador incrementado
			*/
			self_type operator++(void);

			/**
			* @brief Sobrecarga do operador ++ de pós-incremento
			* @return Iterador incrementado
			*/
			self_type operator++(int);

			/**
			* @brief Sobrecarga do operador -- de pré-incremento
			* @return Iterador decrementado
			*/
			self_type operator--(void);

			/**
			* @brief Sobrecarga do operador -- de pós-incremento
			* @return Iterador decrementado
			*/
			self_type operator--(int);

			/**
			* @brief Sobrecarga do operador +
			* @param[in] num valor a ser somado
			* @return Novo iterador
			*/
			self_type operator+( size_type num );

			/**
			* @brief Sobrecarga do operador - de pós-incremento
			* @param[in] num valor a ser subtraido
			* @return Novo iterador
			*/
			self_type operator-( size_type num );

			/**
			* @brief Sobrecarga do operador * para derreferenciar o ponteiro interno
			* @return Referencia para o conteudo do ponteiro interno
			*/
			reference operator*(void);

			/**
			* @brief Sobrecarga do operador * para derreferenciar o ponteiro interno, mas não é possivel alterar seu valor
			* @return Referencia constante para o conteudo do ponteiro interno
			*/
			const_reference operator*(void) const;

			/**
			* @brief Sobrecarga do operador - para calcular a distancia dos dois iteradores envolvidos
			* @param[in] other Iterador a ser subtraido
			* @return Valor numerico da distancia dos dois iteradores
			*/
			difference_type operator-( const MyIterator< value_type >& other );

			/**
			* @brief Sobrecarga do operador != para comparar dois iteradores
			* @param[in] other Iterador a ser comparado
			* @return true se os iteradores são diferentes, false caso contrário
			*/
			bool operator!=(const self_type& other) const;

			/**
			* @brief Sobrecarga do operador == para comparar dois iteradores
			* @param[in] other Iterador a ser comparado
			* @return true se os iteradores são iguais, false caso contrário
			*/
			bool operator==(const self_type& other) const;

			/**
			* @brief Sobrecarga do operador == para comparar um iteradores com um ponteiro
			* @param[in] other Ponteiro a ser comparado
			* @return true se o iterador e o ponteiro são diferentes, false caso contrário
			*/
			bool operator!=(const_pointer other) const;

			/**
			* @brief Sobrecarga do operador == para comparar um iteradores com um ponteiro
			* @param[in] other Ponteiro a ser comparado
			* @return true se o iterador e o ponteiro são iguais, false caso contrário
			*/
			bool operator==(const_pointer other) const;
	};

	template < typename value_type >
	class vector; // Declaração antecipada da classe vector

	template < typename value_type > // Definição antecipada do template para o operador de inserção
	std::ostream& operator<< ( std::ostream&, vector<value_type> & );

	template < typename value_type > // Definição antecipada do template para o metodo swap
	void swap ( vector< value_type >&, vector<value_type> & );

	/**
	* @brief Um tipo simplificado de vector
	* @tparam T Tipo do valor que será utilizado para o template do vector
	*/
	template < typename T >
	class vector
	{
		public:
			typedef T value_type;
			typedef std::size_t size_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef value_type* pointer;
			typedef const value_type* const_pointer;
			typedef std::unique_ptr< value_type > u_pointer;
			typedef std::unique_ptr< const value_type > const_u_pointer;
			typedef std::ptrdiff_t difference_type;
			using iterator = MyIterator< value_type >;
			using const_iterator = MyIterator< const value_type >;

		private:
			pointer m_storage;
			size_t m_end;
			size_t m_capacity;

		public:
			//							===============================
			//							===== [I] SPECIAL MEMBERS =====

			/**
			* @brief Construtor vazio do vector.
			*/
			vector();

			/**
			* @brief Construtor do vector, com um valor inicial de capacidade
			* @param[in] cap capacidade inicial de armazenamento do vector
			*/
			explicit vector( size_type cap );

			/**
			* @brief Construtor do vector, com base em um intervalo 
			* @param[in] first Inicio do intervalor
			* @param[in] last Fim do intervalo
			*/
			template < typename InputItr >
			vector( InputItr first, InputItr last);

			/**
			* @brief Construtor cópia do vector
			* @param[in] other Vector a ser copiado
			*/
			vector( const vector & other);

			/**
			* @brief Construtor do vector a partir de uma lista inicializadora
			* @param[in] ilist Lista a ser utilizada
			*/
			vector( std::initializer_list< value_type > ilist );

			/**
			* @brief Destrutor do vector
			*/
			~vector()
			{
				delete[] m_storage;
			}

			/**
			* @brief Sobrecarga do operador = a partir de outro vector
			* @param[in] other vector a ser atribuido
			* @return O vector já modificado
			*/
			vector& operator=( const vector& other );

			/**
			* @brief Sobrecarga do operador = a partir de uma lista inicializadora
			* @param[in] ilist lista a ser atribuida
			* @return O vector já modificado
			*/
			vector& operator=( std::initializer_list< value_type > ilist );

			//							==========================
			//							===== [II] Iterators =====

			/**
			* @brief Cria e retorna um iterador a partir do endereço do primeiro elemento do vector
			* @return Iterador para o primeiro elemento do vector
			*/
			iterator begin( void );

			/**
			* @brief Cria e retorna um iterador a partir do endereço do ultimo elemento do vector
			* @return Iterador para o ultimo elemento do vector
			*/
			iterator end( void );

			/**
			* @brief Cria e retorna um iterador constante a partir do endereço do primeiro elemento do vector
			* @return Iterador para o primeiro elemento do vector
			*/
			const_iterator cbegin( void ) const;

			/**
			* @brief Cria e retorna um iterador constante a partir do endereço do ultimo elemento do vector
			* @return Iterador para o ultimo elemento do vector
			*/
			const_iterator cend( void ) const;

			//							==========================
			//							===== [III] Capacity =====

			/**
			* @brief Acessa e retorna o tamanho lógico do vector
			* @return tamanho lógico do vector
			*/
			size_type size( void );

			/**
			* @brief Acessa e retorna o tamanho fisico do vector
			* @return tamanho fisico do vector
			*/
			size_type capacity( void );

			/**
			* @brief Verifica se o vector possui algum elemento, isto é o tamanho lógico é 0
			* @return true se ele não está vazio, false caso esteja
			*/
			bool empty( void );
			//							===========================
			//							===== [IV] Modifiers =====

			/**
			* @brief Zera o tamanho lógico do vector
			*/
			void clear( void );

			/**
			* @brief Adiciona o elemento indicado ao inicio do vector
			* @param[in] valor a ser adicionado
			*/
			void push_front( const_reference value );

			/**
			* @brief Adiciona o elemento indicado ao fim do vector
			* @param[in] valor a ser adicionado
			*/
			void push_back (const_reference value );

			/**
			* @brief Elimina o ultimo elemento do vector
			*/
			void pop_back( void );

			/**
			* @brief Elimina o primeiro elemento do vector
			*/
			void pop_front( void );

			/**
			* @brief Insere o elemento indicado na posição indicada pelo iterador
			* @param[in] itrt Iterador que indica a posição
			* @param[in] value Elemento a ser inserido
			* @return Iterador que indica a posição do elemento inserido ( a mesma que foi passada )
			*/
			iterator insert( iterator itrt, const_reference value );

			/**
			* @brief Insere todos os elementos indicados do intervalo indicado no vector
			* a partir posição indicada pelo iterador
			* @param[in] itrt Iterador que indica a posição inicial
			* @param[in] first Inicio do intevalo indicado
			* @param[in] last Fim do intevalo indicado
			* @return Iterador que indica a posição do ultimo elemento inserido
			*/
			template < typename InputItr >
			iterator insert( iterator itrt, InputItr first, InputItr last);

			/**
			* @brief Insere todos da lista inicializadora indicada no vector
			* a partir posição indicada pelo iterador
			* @param[in] itrt Iterador que indica a posição inicial
			* @param[in] ilist Lista inicializadora
			* @return Iterador que indica a posição do ultimo elemento inserido
			*/
			iterator insert( iterator itrt, std::initializer_list< value_type > ilist );

			/**
			* @brief Aumenta a capacidade do vector para o valor indicado
			* @param[in] new_cap Nova capacidade do vector
			*/
			void reserve (size_type new_cap);

			/**
			* @brief Reduz a capacidade do vector para exatamente o numero de elementos
			*/
			void shrink_to_fit( void );

			/**
			* @brief Aumenta a capacidade do vector para o valor indicado
			* @param[in] new_cap Nova capacidade do vector
			*/
			void assign( const_reference value);

			/**
			* @brief Aumenta a capacidade do vector para o valor indicado
			* @param[in] new_cap Nova capacidade do vector
			*/
			void assign( std::initializer_list< value_type > ilist );

			/**
			* @brief Substitui todos os elementos do vector pelos do intervalo indicado
			* @details Se o fim do intervalo for alcançado, os proximos elementos do vector 
			* serão substituidos pela lista novamente, de maneira repetitiva até o vector ficar completo
			* @param[in] first Inicio do intervalo
			* @param[in] last Fim do intervalo
			*/
			template < typename InputItr >
			void assign( InputItr first, InputItr last);

			/**
			* @brief Retira do vector os elementos no intervalo indicado
			* @param[in] first Inicio do intervalo
			* @param[in] last Fim do intervalo
			* @return Retorna um iterador para a ultima posição válida do vector
			*/
			iterator erase( iterator first, iterator last );

			/**
			* @brief Retira do vector o elemento da itrtição indicada
			* @param[in] pos Iterador para a posição do elemento a ser retirado
			* @return Retorna um iterador para a ultima posição válida do vector
			*/
			iterator erase( iterator itrt );

			//							==============================
			//							===== [V] Element access =====
			

			/**
			* @brief Acessa o ultimo elemento do vector
			* @return Retorna uma referencia para o ultimo elemento do vector
			*/
			reference back( void );

			/**
			* @brief Acessa o primeiro elemento do vector
			* @return Retorna uma referencia para o primeiro elemento do vector
			*/
			reference front(void);

			/**
			* @brief Acessa o primeiro elemento do vector, mas não é possivel alterar o seu valor
			* @return Retorna uma referencia constante para o primeiro elemento do vector
			*/
			const_reference back( void ) const;

			/**
			* @brief Acessa o primeiro elemento do vector, mas não é possivel alterar o seu valor
			* @return Retorna uma referencia constante para o primeiro elemento do vector
			*/
			const_reference front( void ) const;

			/**
			* @brief Acessa o elemento do vector indicado pelo indice passado
			* @param[in] id Indice para a posição do elemento a ser acessado
			* @return Retorna uma referencia constante para o elemento acessado
			*/
			reference operator[]( size_type id );
			
			/**
			* @brief Acessa o elemento do vector indicado pelo indice passado, mas não é possivel alterar o seu valor
			* @param[in] id Indice para a posição do elemento a ser acessado
			* @return Retorna uma referencia constante para o elemento acessado
			*/
			const_reference operator[]( size_type id ) const;

			/**
			* @brief Acessa o elemento do vector indicado pelo indice passado
			* @details Realiza uma verificação para saber se o indice passado é válido.
			* Caso não seja, lança a excessão out_of_range 
			* @param[in] id Indice para a posição do elemento a ser acessado
			* @return Retorna uma referencia constante para o elemento acessado
			*/
			reference at( size_type id );

			/**
			* @brief Acessa o elemento do vector indicado pelo indice passado, mas não é possivel alterar o seu valor
			* @details Realiza uma verificação para saber se o indice passado é válido.
			* Caso não seja, lança a excessão out_of_range 
			* @param[in] id Indice para a posição do elemento a ser acessado
			* @return Retorna uma referencia constante para o elemento acessado
			*/
			const_reference at( size_type id ) const;
			
			/**
			* @brief Acessa o vetor interno do vector
			* @return Retorna um pointeiro para o vetor interno
			*/
			pointer data( void );

			/**
			* @brief Acessa o vetor interno do vector, mas não é possivel alterar seu valor
			* @return Retorna um pointeiro constante para o vetor interno
			*/
			const_pointer data( void ) const;

			//								==========================
			//								===== [VI] Operators =====

			/**
			* @brief sobrecarga do operador de ==
			* @return true se forem iguais, false caso contrário
			*/
			bool operator==( const vector & other) const;

			/**
			* @brief sobrecarga do operador de !=
			* @return true se forem diferentes, false caso contrário
			*/
			bool operator!=( const vector & other) const;

			//							==================================
			//							===== [VII] Friend Functions =====

			//friend std::ostream& operator<< <value_type>(std::ostream &os_, vector<value_type> const &v_);

			/**
			* @brief Sobrecarga falha do operador de << para mostrar o conteudo do vector
			* @param[in] os_ Stream de saída do conteudo do vector
			* @param[in] v_ Vector alvo
			* @return Retorna um stream de saída com o conteudo do vector já formatado
			*/
			friend std::ostream& operator<< (std::ostream &os_, vector<value_type> &v_)
			{
				os_ << "[ ";
				for( size_type i = 0 ; i < v_.size() ; ++i )
					os_ << v_.m_storage[i] << " ";
				os_ << "| ";
				for( size_type i = v_.size() ; i < v_.capacity() ; ++i )
					os_ << v_.m_storage[i] << " ";
				os_ << "]";
				os_ << " Tamanho Lógico: " << v_.size() << ", Tamanho Físico: " << v_.capacity() << std::endl;
				return os_;	
			}

			friend void swap < value_type >( vector< value_type > & first_, vector< value_type > & second_ );

			/**
			* @brief Sobrecarga do método swap da std
			* @param[in] first_ Primeiro vector a ser trocado
			* @param[in] second_ Segundo vector a ser trocado
			*/
			friend void swap ( vector< value_type > & first_, vector< value_type > & second_ )
			{
				sc::vector< value_type > temp(first_);
				first_ = second_;
				second_ = temp;
			}

			/**
			* @brief Método swap da própria classe
			* @param[in] other Primeiro vector a ser trocado
			*/
			void swap ( vector< value_type > & other );

			/**
			* @brief Método que mostra o conteudo do vector na saida (stream) padrão
			*/
			void print () const;
	};
}

#include "MyIterator.inl"
#include "vector_Special_Members.inl"
#include "vector_Iterators_Capacity.inl"
#include "vector_Modifiers.inl"
#include "vector_Element_Access.inl"
#include "vector_Operators_Friend_Functions.inl"

#endif
/**
* @file		lista_driver.cpp
* @brief	Testes dos metodos da classe ls::list
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/11/2017
* @date		25/11/2017	
*/

#include <iostream>
#include <cassert> // assert
#include <initializer_list>

#include "list.hpp"

/**
 * @brief      Função auxiliar para imprimir os dados da lista informada
 *
 * @param[in]  target  A lista alvo
 *
 * @tparam     T       Tipo de dado armazenado na lista
 */
template < typename T >
void print_list ( ls::list< T > target )
{
	std::cout << "[ ";
	for ( auto i = target.cbegin(); i != target.cend(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "]" << std::endl;
}


/**
 * @brief      Programa Principal
 *
 * @param[in]  argc  The argc
 * @param      argv  The argv
 *
 * @return     0
 */
int main(int argc, char const *argv[])
{

	std::cout << "\t\t===== Iniciando Testes =====" << std::endl;

	std::cout << ">>> Construtor vazio" << std::endl;

{
	ls::list< int > list_int;

	std::cout << ">>> size()" << std::endl;
	assert( list_int.size() == 0 );
	
	std::cout << ">>> empty()" << std::endl;
	assert( list_int.empty() == true );
}

	std::cout << ">>> Construtor com capacidade inicial" << std::endl;

{	
	ls::list< char > list_c(20);

	std::cout << ">>> size()" << std::endl;
	assert( list_c.size() == 20 );
}

	std::cout << ">>> Construtor por lista inicializadora" << std::endl;

{
	ls::list< std::string > list_string {"Testando", "Lista", "Inicializadora"};

	std::cout << ">>> size()" << std::endl;
	assert( list_string.size() == 3 );
	
	std::cout << ">>> empty()" << std::endl;
	assert( list_string.empty() == false );

	std::cout << ">>> front()" << std::endl;
	assert (list_string.front() == "Testando");

	std::cout << ">>> back()" << std::endl;
	assert (list_string.back() == "Inicializadora");

	std::cout << ">>> Construtor cópia" << std::endl;

	ls::list< std::string > list_string_copy(list_string);

	std::cout << ">>> Operador igualdade ( == )" << std::endl;
	assert (list_string_copy == list_string);

	std::cout << ">>> Push_back()" << std::endl;

	list_string.push_back("Original");
	assert (list_string.back() == "Original");

	std::cout << ">>> Push_front()" << std::endl;

	list_string_copy.push_front("Cópia");
	assert (list_string_copy.front() == "Cópia");

	std::cout << ">>> Operador diferença ( != )" << std::endl;
	assert (list_string_copy != list_string);

	std::cout << ">>> Find() " << std::endl;
	assert( list_string_copy.find( "Cópia" ) == list_string_copy.cbegin() );
	assert( list_string.find( "Original" ) == list_string.cend()-1 );
}

	std::cout << ">>> Construtor por intervalo" << std::endl;

{	
	std::cout << ">>> cbegin() e cend()" << std::endl;
	ls::list< int > list_int { 20, 30 };
	ls::list< int > interval_int(list_int.cbegin(), list_int.cend());

	std::cout << std::endl << ">>> Testes acima realizados com sucesso. Iniciando parte II" << std::endl << std::endl;

	std::cout << ">>> insert() - Parte I" << std::endl;
	std::cout << "Antes do insert: \t";
	print_list(interval_int);

	interval_int.insert( interval_int.begin(), 10);

	std::cout << "Após o insert: \t\t";
	print_list(interval_int);

	std::cout << ">>> insert() - Parte II" << std::endl;
	std::cout << "Antes do insert: \t";
	print_list(interval_int);

	interval_int.insert( interval_int.begin(), { 11 , 12 , 13 });

	std::cout << "Após o insert: \t\t";
	print_list(interval_int);

	std::cout << ">>> insert() - Parte III" << std::endl;
	std::cout << "Antes do insert: \t";
	print_list(interval_int);

	interval_int.insert( interval_int.cend()-2, interval_int.begin()+1, interval_int.begin()+2 );

	std::cout << "Após o insert: \t\t";
	print_list(interval_int);

	std::cout << ">>> Operador de atribuição ( = )" << std::endl;
	
	std::cout << "Antes da atribuição:" << std::endl;
	std::cout << "list_int: \t\t";
	print_list(list_int);

	std::cout << "interval_int: \t\t";
	print_list(interval_int);
	
	list_int = interval_int;

	assert (list_int.front() == interval_int.front());

	std::cout << "Após a atribuição:" << std::endl;
	std::cout << "list_int: \t\t";
	print_list(list_int);

	std::cout << "interval_int: \t\t";
	print_list(interval_int);

	std::cout << ">>> Pop_back() \t\t" ;
	interval_int.pop_back();
	print_list(interval_int);

	std::cout << ">>> Pop_front()\t\t";
	interval_int.pop_front();
	print_list(interval_int);

	std::cout << "Antes do assign: \t";
	print_list(interval_int);

	interval_int.assign( 3ul, 10 );

	std::cout << "Após o assign: \t\t";
	print_list(interval_int);

}

{
	ls::list< char > list_char(27);
	assert (list_char.size() == 27);
	std::cout << ">>> assign()" << std::endl;

	std::cout << "Antes do assign: \t";
	print_list(list_char);

	list_char.assign({'t','e','s','t','a','n','d','o','!'});

	std::cout << "Após o assign: \t\t";
	print_list(list_char);

	std::cout << "Antes do assign: \t";
	print_list(list_char);

	list_char.assign( 8, '#');

	std::cout << "Após o assign: \t\t";
	print_list(list_char);

	std::cout << ">>> erase()" << std::endl;

	std::cout << "Antes do erase: \t";
	print_list(list_char);

	list_char.erase(list_char.begin(), list_char.end()-1);

	std::cout << "Após o erase: \t\t";
	print_list(list_char);

	std::cout << ">>> erase()" << std::endl;

	std::cout << "Antes do erase: \t";
	print_list(list_char);

	list_char.erase(list_char.begin());

	std::cout << "Após o erase: \t\t";
	print_list(list_char);
}

{
	ls::list<char> l_assign = {'a','b','c','d'};
	std::cout << ">>> assign()" << std::endl;

	std::cout << "Antes do assign: \t";
	print_list(l_assign);

	l_assign.assign('?');

	std::cout << "Após o assign: \t\t";
	print_list(l_assign);

	std::cout << ">>> clear()" << std::endl;

	std::cout << "Antes do clear: \t";
	print_list(l_assign);

	l_assign.clear();
	assert (l_assign.size() == 0);

	std::cout << "Após o clear: \t\t";
	print_list(l_assign);
}

	return 0;
}
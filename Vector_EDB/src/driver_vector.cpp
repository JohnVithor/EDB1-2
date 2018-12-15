/**
* @file		driver_vector.hpp
* @brief	Testes dos metodos da classe sc::vector 
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	18/10/2017
* @date		21/10/2017	
*/

#include <iostream>
#include <cassert> // assert

#include "vector.hpp"

int main(int argc, char const *argv[])
{
	std::cout << "\t\t===== Iniciando Testes =====" << std::endl;
	
{
	std::cout << ">>> swap()" << std::endl;	

	sc::vector<double> trocar1 {6, 7, 8.2, 9, 10};
	sc::vector<double> trocar2 {1, 2.1, 3, 4, 5,6,6};

	std::cout << "Antes do swap: " << std::endl;	
	std::cout << "trocar1 :" << trocar1;
	std::cout << "trocar2 :" << trocar2;

	std::swap(trocar1,trocar2);

	std::cout << "Após o swap: "  << std::endl;	
	std::cout << "trocar1 :" << trocar1;
	std::cout << "trocar2 :" << trocar2;	
}


	std::cout << ">>> Construtores vazios" << std::endl;

{
	sc::vector< int > vec_int;

	std::cout << ">>> size()" << std::endl;
	assert( vec_int.size() == 0 );
	
	std::cout << ">>> capacity()" << std::endl;
	assert( vec_int.capacity() == 1 );
	
	std::cout << ">>> empty()" << std::endl;
	assert( vec_int.empty() == true );
}

	std::cout << ">>> Construtor com capacidade inicial" << std::endl;

{	
	sc::vector< char > vec_c(20);

	std::cout << ">>> capacity()" << std::endl;
	assert( vec_c.capacity() == 20 );
}

	std::cout << ">>> Construtor por lista inicializadora" << std::endl;

{
	sc::vector< std::string > vec_string {"Testando", "Construtor", "Lista", "Inicializadora"};

	std::cout << ">>> size()" << std::endl;
	assert( vec_string.size() == 4 );
	
	std::cout << ">>> capacity()" << std::endl;
	assert( vec_string.capacity() == 4 );

	std::cout << ">>> empty()" << std::endl;
	assert( vec_string.empty() == false );

	std::cout << ">>> front()" << std::endl;
	assert (vec_string.front() == "Testando");

	std::cout << ">>> Operador[]" << std::endl;
	assert (vec_string[1] == "Construtor");

	std::cout << ">>> at()" << std::endl;
	assert (vec_string.at(2) == "Lista");

	std::cout << ">>> back()" << std::endl;
	assert (vec_string.back() == "Inicializadora");

	std::cout << ">>> Construtor cópia" << std::endl;

	sc::vector< std::string > vec_string_copy(vec_string);

	std::cout << ">>> Operador igualdade ( == )" << std::endl;
	assert (vec_string_copy == vec_string);

	std::cout << ">>> Push_back()" << std::endl;

	vec_string.push_back("Original");
	assert (vec_string[4] == "Original");

	std::cout << ">>> Push_front" << std::endl;

	vec_string_copy.push_front("Cópia");
	assert (vec_string_copy[0] == "Cópia");

	std::cout << ">>> Operador diferença ( != )" << std::endl;
	assert (vec_string_copy != vec_string);
}

	std::cout << ">>> Construtor por intervalo" << std::endl;

{	
	std::cout << ">>> cbegin() e cend()" << std::endl;
	sc::vector< int > list_int {20, 30};
	sc::vector< int > interval_int(list_int.cbegin(), list_int.cend());

	assert (interval_int[0] == 20);
	assert (interval_int[1] == 30);

	std::cout << ">>> insert() - Parte I" << std::endl;
	std::cout << "Antes do insert: " << interval_int;

	interval_int.insert( interval_int.begin(), 10);

	std::cout << "Após o insert: " << interval_int;

	std::cout << ">>> insert() - Parte II" << std::endl;
	std::cout << "Antes do insert: " << interval_int;

	interval_int.insert( interval_int.begin()+1, { 11 , 12 , 13 });

	std::cout << "Após o insert: " << interval_int;
	
	std::cout << ">>> insert() - Parte III" << std::endl;
	std::cout << "Antes do insert: " << interval_int;

	interval_int.insert( interval_int.begin()+3, interval_int.begin(), interval_int.end());

	std::cout << "Após o insert: " << interval_int;

	std::cout << ">>> Operador de atribuição ( = )" << std::endl;
	
	std::cout << "Antes da atribuição: " << interval_int;
	std::cout << "list_int: " << list_int;
	std::cout << "interval_int: " << interval_int;
	
	list_int = interval_int;

	assert (list_int.at(3) == interval_int.at(3));
	assert (list_int.front() == interval_int.front());

	std::cout << "Após a atribuição: " << interval_int;
	std::cout << "list_int: " << list_int;
	std::cout << "interval_int: " << interval_int;
}

{

	sc::vector< char > vec_char(25);
	assert (vec_char.capacity() == 25);
	vec_char = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'};
	std::cout << ">>> assign()" << std::endl;

	std::cout << "Antes do assign: " << vec_char;
	vec_char.assign({'t','e','s','t','a','n','d','o','!'});
	std::cout << "Após'o assign: " << vec_char;

	std::cout << ">>> erase()" << std::endl;

	std::cout << "Antes do erase: " << vec_char;
	vec_char.erase(vec_char.begin(), vec_char.begin()+15);
	std::cout << "Após o erase: " << vec_char;

	std::cout << ">>> erase()" << std::endl;

	std::cout << "Antes do erase: " << vec_char;
	vec_char.erase(vec_char.begin()+2);
	std::cout << "Após'o erase: " << vec_char;	

	std::cout << ">>> shrink_to_fit()" << std::endl;

	std::cout << "Antes do shrink_to_fit: " << vec_char;
	vec_char.shrink_to_fit();
	assert (vec_char.size() == vec_char.capacity());
	std::cout << "Após'o shrink_to_fit: " << vec_char;
}

{
	sc::vector<char> v_assign {'a','b','c','d'};
	std::cout << ">>> assign()" << std::endl;

	std::cout << "Antes do assign: " << v_assign;
	v_assign.assign('?');
	std::cout << "Após o assign: " << v_assign;	

	std::cout << ">>> clear()" << std::endl;
	std::cout << "Antes do clear: " << v_assign;
	v_assign.clear();
	assert (v_assign.size() == 0);
	std::cout << "Após o clear: " << v_assign;
}
	return 0;
}
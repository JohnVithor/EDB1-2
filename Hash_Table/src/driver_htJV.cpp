#include <iostream>
#include <functional>
#include <tuple>

#include "hashtbl.hpp"

using namespace ac;

// Tipo conta-corrente.
struct Account
{
	//=== Public members
	std::string m_client_name;
	int m_bank_code;
	int m_branch_code;
	int m_acc_number;
	float m_balance;

	//=== Alias
	typedef int AcctKey1;
	typedef std::pair< std::string, int > AcctKey2;
	typedef std::tuple< std::string, int, int, int > AcctKey3;

	//=== Special members
	Account( std::string n_ = "<empty>",
			int bnc_ = 1,       // Banco do Brasil.
			int brc_ = 1668,    // Ag. Campus UFRN
			int nmr_ = 0,       // Numero da conta
			float bal_ = 0.f )  // Saldo
		: m_client_name( n_ ),
		m_bank_code( bnc_ ),
		m_branch_code( brc_ ),
		m_acc_number( nmr_ ),
		m_balance( bal_ )
	{ /* Empty */ }

	//=== Public interface
	/// Retorna a chave associada com a conta-corrente (Versoes 1, 2 e 3 ).
	AcctKey1 get_key1()
	{
		return m_acc_number;
	}

	AcctKey2 get_key2()
	{
		return std::make_pair( m_client_name, m_acc_number );
	}

	AcctKey3 get_key3()
	{
		return std::make_tuple( m_client_name, m_bank_code, m_branch_code, m_acc_number );
	}

	// DEBUG: Imprime uma formatacao para a conta-corrente.
	inline friend std::ostream &operator<< ( std::ostream & _os, const Account & _acct )
	{
		_os << "[ Client: <" << _acct.m_client_name <<
			"> Bank: <"   << _acct.m_bank_code <<
			"> Branch: <" << _acct.m_branch_code <<
			"> Number: <" << _acct.m_acc_number <<
			"> Balance: <" << _acct.m_balance << "> ]";
		return _os;
	}
};

/// Functor representando a função de dispersão primátia (fp) para a chave (versão 1).
struct KeyHash1
{
	std::size_t operator()( const Account::AcctKey1 & k_ ) const
	{
		// This is just to debug.
		std::cout << ">>> [KeyHash()]: key = " << std::hash< int >()( k_ ) << std::endl;
		// Calcular o valore de dispersao.
		return std::hash< int >()( k_ );
	}
};

/// Functor representando a comparacao entre chaves (versão 1).
struct KeyEqual1
{
	bool operator()( const Account::AcctKey1 & _lhs, const Account::AcctKey1 & _rhs ) const
	{
		return ( _lhs == _rhs );
	}
};


/// Functor representando a função de dispersão primátia (fp) para a chave (versão 1).
struct KeyHash2
{
	std::size_t operator()( const Account::AcctKey2 & k_ ) const
	{
		// This is just to debug.
		std::cout << ">>> [KeyHash()]: key = " << std::hash< std::string >()( k_.first )
		<< ", " << std::hash< int >()( k_.second ) << std::endl;

		// Calcular o valore de dispersao.
		return std::hash< std::string >()( k_.first ) xor std::hash< int >()( k_.second );
	}
};

/// Functor representando a comparacao entre chaves (versão 1).
struct KeyEqual2
{
	bool operator()( const Account::AcctKey2 & _lhs, const Account::AcctKey2 & _rhs ) const
	{
		return ( _lhs.first == _rhs.first and _lhs.second == _rhs.second );
	}
};

/// Functor representando a função de dispersão primátia (fp) para a chave (versão 1).
struct KeyHash3
{
	std::size_t operator()( const Account::AcctKey3 & k_ ) const
	{
		// This is just to debug.
		std::cout << ">>> [KeyHash()]: key = " << std::hash< std::string >()( std::get<0>(k_) )
		<< ", " << std::hash< int >()( std::get<1>(k_) ) << ", " << std::hash< int >()( std::get<2>(k_) )
		<< ", " << std::hash< int >()( std::get<3>(k_) ) << std::endl;

		// Calcular o valore de dispersao.
		return std::hash< std::string >()( std::get<0>(k_) ) xor std::hash< int >()( std::get<1>(k_) )
				   xor std::hash< int >()( std::get<2>(k_) ) xor std::hash< int >()( std::get<3>(k_) );
	}
};

/// Functor representando a comparacao entre chaves (versão 1).
struct KeyEqual3
{
	bool operator()( const Account::AcctKey3 & _lhs, const Account::AcctKey3 & _rhs ) const
	{
		return ( std::get<0>(_lhs) == std::get<0>(_rhs) and std::get<1>(_lhs) == std::get<1>(_rhs)
			and  std::get<2>(_lhs) == std::get<2>(_rhs) and std::get<3>(_lhs) == std::get<3>(_rhs) );
	}
};


int main()
{

	Account acct("Alex Bastos", 1, 1668, 54321, 1500.f);

	Account myAccounts[] =
		{
			{"Alex Bastos", 1, 1668, 54321, 1500.f},
			{"Aline Souza", 1, 1668, 45794, 530.f},
			{"Cristiano Ronaldo", 13, 557, 87629, 150000.f},
			{"Jose Lima", 18, 331, 1231, 850.f},
			{"Saulo Cunha", 116, 666, 1, 5490.f}
		};

	// Cria uma tabela de dispersao com capacidade p 23 elementos

	std::cout << ">>> Contas 1: " << std::endl;	
	HashTbl< Account::AcctKey1, Account, KeyHash1, KeyEqual1 > contas1( 20 );
	std::cout << ">>> size: " << contas1.size() << std::endl;	
	contas1.insert( myAccounts[2].get_key1(), myAccounts[2] );
	contas1.insert( myAccounts[0].get_key1(), myAccounts[0] );
	contas1.insert( myAccounts[3].get_key1(), myAccounts[3] );
	contas1.insert( myAccounts[1].get_key1(), myAccounts[1] );
	contas1.insert( myAccounts[4].get_key1(), myAccounts[4] );

	std::cout << std::endl;

	std::cout << ">>> Contas 2: " << std::endl;	
	HashTbl< Account::AcctKey2, Account, KeyHash2, KeyEqual2 > contas2( 20 );
	std::cout << ">>> size: " << contas2.size() << std::endl;	
	contas2.insert( myAccounts[2].get_key2(), myAccounts[2] );
	contas2.insert( myAccounts[0].get_key2(), myAccounts[0] );
	contas2.insert( myAccounts[3].get_key2(), myAccounts[3] );
	contas2.insert( myAccounts[1].get_key2(), myAccounts[1] );
	contas2.insert( myAccounts[4].get_key2(), myAccounts[4] );

	std::cout << std::endl;

	std::cout << ">>> Contas 3: " << std::endl;	
	HashTbl< Account::AcctKey3, Account, KeyHash3, KeyEqual3 > contas3( 23 );
	std::cout << ">>> size: " << contas3.size() << std::endl;	
	contas3.insert( myAccounts[2].get_key3(), myAccounts[2] );
	contas3.insert( myAccounts[0].get_key3(), myAccounts[0] );
	contas3.insert( myAccounts[3].get_key3(), myAccounts[3] );
	contas3.insert( myAccounts[1].get_key3(), myAccounts[1] );
	contas3.insert( myAccounts[4].get_key3(), myAccounts[4] );

	std::cout << std::endl;

	std::cout << "\t\t\t\tContas 1: " << std::endl;	
	std::cout << "=======================================================" << std::endl;
	contas1.print1();
		
	std::cout << "\t\t\t\tContas 2: " << std::endl;	
	std::cout << "=======================================================" << std::endl;
	contas2.print2();
		
	std::cout << "\t\t\t\tContas 3: " << std::endl;	
	std::cout << "=======================================================" << std::endl;
	contas3.print3();

	std::cout << "\t\t\t\tRetrieves: " << std::endl;

	Account conta1, conta2, conta3;

	contas1.retrieve( myAccounts[2].get_key1(), conta1 );
	std::cout << conta1.m_client_name << std::endl;

	contas2.retrieve( myAccounts[2].get_key2(), conta2 );
	std::cout << conta2.m_client_name << std::endl;

	contas3.retrieve( myAccounts[2].get_key3(), conta3 );
	std::cout << conta3.m_client_name << std::endl;

	std::cout << std::endl;

	std::cout << ">>> Contas: " << std::endl;	

	std::cout << contas3 << std::endl;

	for( auto & e : myAccounts )
		std::cout << e << std::endl;

		std::cout << "\n\n>>> Normal exiting...\n";
	return EXIT_SUCCESS;
}

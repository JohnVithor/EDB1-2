#include <iostream>  // cout, endl
#include <algorithm> // copy
#include <iterator>  // ostream_iterator, begin(), end()
#include <cassert>	 // assert() 

int * linear_search (int * first_, int * last_, int target){
    while (first_ != last_ and * first_ != target and *first_ < target) {
        ++first_;
    }
    return first_;
}

int * linear_search_sorted (int * first_, int * last_, int target){
    while (first_ != last_ and *first_ != target and *first_ < target) {
        ++first_;
    }
	return (*first_ == target ) ? first_ : last_;
}

int * binary_search_recursive (int *vetor, int tamanho, int target){
	int *meio = vetor + tamanho/2;
	if (target > *meio){
		return binary_search_recursive(meio, tamanho/2, target);
	} else if (target < *meio){
		return binary_search_recursive(vetor, tamanho/2, target);
	} else {
		printf("Não está no vetor\n");
		return NULL;
	}
	return meio;
}
int * binary_search (int *vetor, int tamanho, int target){
	int *meio = vetor;
	tamanho = tamanho/2;
	while(*meio != target){
		meio = vetor + tamanho + 1;
		if (target > *meio){
			vetor = meio;
			tamanho = tamanho/2;
		} else if (target < *meio){
			tamanho = tamanho/2;
		} else {
			std::cout << "Não está no vetor\n";
			return NULL;
		}
	}
	return meio;
}

int * binary_search_recursive2 (int *primeiro, int *ultimo, int target){
	int *meio = (int*) (primeiro + (int)((ultimo - primeiro)/2));	// Josivan
	if (target == *meio){
		return meio;
	} else if (target > *meio){
		return binary_search_recursive2(meio, ultimo, target);
	} else if (target < *meio){
		return binary_search_recursive2(primeiro, meio, target);
	} else {
		std::cout << "Não está no vetor\n";
		return NULL;
	}
}

int * binary_search2 (int *primeiro, int *ultimo, int target){
	int dist = (int)((ultimo - primeiro)/2);
	int *meio = (int*) (primeiro + dist);
	while (*meio != target){
		if (target > *meio){
			dist = (ultimo - meio)/2;
			primeiro = meio;
			meio = primeiro + dist;
		} else if (target < *meio){
			dist = (meio - primeiro)/2;
			meio = primeiro + dist;
		} else {
			std::cout << "Não está no vetor\n";
			return NULL;
		}
	}
	return meio;
}

int * ternary_search_recusirve (int *vetor, int tamanho, int target){
	int *meio_e = vetor + tamanho/3;
	int *meio_d = vetor + 2*tamanho/3;
	
	if (target < *meio_e){
		return ternary_search_recusirve(vetor, tamanho/3, target);
	} else if (target == *meio_e){
		return meio_e;
	} else if (target < *meio_d){
		return ternary_search_recusirve(meio_e, tamanho/3, target);
	} else if (target == *meio_d){
		return meio_d;
	} else if (target > *meio_d){
		return ternary_search_recusirve(meio_d, tamanho/3, target);
	} else {
		std::cout << "Não está no vetor\n";
		return NULL;
	}
}

int * ternary_search (int *vetor, int tamanho, int target){
	int *meio_e = vetor;
	int *meio_d = vetor;

	tamanho = tamanho/3;
	while(*meio_e != target && *meio_d != target){
		meio_e = vetor + tamanho;
		meio_d = vetor + 2*tamanho;
		if (target < *meio_e){
			tamanho = tamanho/3;
		} else if (target < *meio_d){
			vetor = meio_e;
			tamanho = tamanho/3;
		} else if (target > *meio_d){
			vetor = meio_d;
			tamanho = tamanho/3;
		} else {
			std::cout << "Não está no vetor\n";
			return NULL;
		}
	}
	if (target == *meio_d){
		return meio_d;
	} else {
		return meio_e;	
	}
}

int * ternary_search_recusirve2 (int *primeiro, int *ultimo, int target){
	int * meio_e = (int*) (primeiro + (int)((ultimo - primeiro)/3));	// Josivan
	int * meio_d = (int*) (primeiro + (int)2*((ultimo - primeiro)/3));	// Josivan
		
	if (*meio_e == target){
		return meio_e;
	} else if (target < *meio_e){
		return ternary_search_recusirve2(primeiro, meio_e, target);
	} else if (target < *meio_d){
		return ternary_search_recusirve2(meio_e, meio_d, target);
	} else if (target > *meio_d){
		return ternary_search_recusirve2(meio_d, ultimo, target);
	} else {
		std::cout << "Não está no vetor\n";
		return NULL;
	}
}

int * ternary_search2 (int *primeiro, int *ultimo, int target){
	int dist_e = (int) (ultimo - primeiro)/3;
	int * meio_e = (int*) (primeiro + dist_e);
	int dist_d = (int)2*(ultimo - primeiro)/3;
	int * meio_d = (int*) (primeiro + dist_d);

	while(*meio_e != target and *meio_d != target){
		meio_e = primeiro + dist_e;
		meio_d = primeiro + dist_d;
		std::cout << meio_e << " meio_e\n";
		std::cout << meio_d << " meio_d\n";
		if (target < *meio_e){
			dist_e = (int) (meio_e - primeiro)/3;
			dist_d = (int)2*(meio_e - primeiro)/3;
			std::cout << meio_e << " meio_e\n";
			std::cout << meio_d << " meio_d\n";
		} else if (target < *meio_d){
			dist_e = (int) (meio_d - meio_e)/3;
			dist_d = (int)2*(meio_d - meio_e)/3;
			std::cout << meio_e << " meio_e\n";
			std::cout << meio_d << " meio_d\n";
		} else if (target > *meio_d){
			dist_e = (int) (ultimo - meio_d)/3;
			dist_d = (int)2*(ultimo - meio_d)/3;
		}
	}
	if (target == *meio_d){
		return meio_d;
	} else {
		return meio_e;	
	}
}

int * binary_search_P(int* first_,int* last_, int target){
	int count = std::distance(first_, last_);
	
	while(count > 0){
		int* M = first_ + count/2;	// auto M(first_);  std::advance ( m , count/2);
		if (*M == target){
			return M;
		} else if(*M > target){
			count = count/2;
		} else {
			first_ = ++M;
			if (count%2 == 0){
				count = count/2 - 1;
			} else {
				count = count/2;
			}
		}
	}
	return last_;
}

int main()
{
    int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    std::cout << "Array: [ ";
    std::copy( std::begin(A), std::end(A), std::ostream_iterator<int>( std::cout , " " ) );
    std::cout << "]\n";

    for (auto i(0u); i < sizeof(A)/sizeof(int); ++i){
    	auto result = binary_search_P( std::begin(A), std::end(A), A[i] );
    	assert(*result == A[i]);
    }
	auto result = binary_search_P( std::begin(A), std::end(A), -1 );
    assert(result == std::end(A));

	std::cout << ">>> Deu Certo\n";
/*
    auto value(0);
    std::cout << "Digite um numero inteiro menor que 10 e maior que 0: ";
    std::cin >> value;

    //auto target = linear_search( std::begin(A), std::end(A), value );
    
    auto target = binary_search_recursive2( std::begin(A), std::end(A), value );
    auto target2 = binary_search2( std::begin(A), std::end(A), value );
    //auto target = ternary_search_recusirve( A, sizeof(A)/sizeof(int), value );
    //auto target2 = ternary_search( A, sizeof(A)/sizeof(int), value );
    
    if ( target != std::end(A) ){
        std::cout << ">>> Found <" << value << "> at position "
                  << std::distance(std::begin(A),target) << ".\n";
    }
    else {
        std::cout << ">>> Value <" << value << "> not found in array!\n";
    }

    if ( target2 != std::end(A) ){
        std::cout << ">>> Found <" << value << "> at position "
                  << std::distance(std::begin(A),target2) << ".\n";
    }
    else {
        std::cout << ">>> Value <" << value << "> not found in array!\n";
    }
*/
    return 0;
}

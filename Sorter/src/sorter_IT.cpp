/**
 * @file sorter_IT.cpp
 * @brief      Arquivo com a implementação das funções de ordenação (Iterador)
 * @author     João Vítor Venceslau Coelho
 * @since      23/09/2017
 * @date       13/03/2018
 */

#include <iostream>		//	std::cout
#include <vector>		//	std::vector
#include <iterator>		//	std::distance
#include <algorithm>	//	std::swap std::copy

#include "sorter_IT.hpp"

using ValueType = unsigned int;
using UnsignedIterator = std::vector<ValueType>::iterator;

void insertion_sort_iterator(UnsignedIterator first, UnsignedIterator last) {
	for (ValueType i = 1; i < std::distance(first, last); ++i) {
		ValueType key = first[i];
		ValueType j = i - 1;
		/* Caso o ValueType seja alterado possa ser necessário adicionar a seguinte
		condição: j >= 0, pois valores negativos provavelmente serão possíveis */
		while (j != std::numeric_limits<ValueType>::max() and first[j] > key) {
			first[j + 1] = first[j];
			--j;
		}
		first[j+1] = key;
	}
}

void selection_sort_iterator(UnsignedIterator first, UnsignedIterator last) { // Parece estranho... falta alguma coisa..
	UnsignedIterator aux = first;
	while(first != last) {
		UnsignedIterator smaller = aux;
		while(aux != last) {
			if (*aux < *smaller) {
				smaller = aux;
			}
			++aux;
		}
		std::swap(*first, *smaller);
		++first;
		aux = first;
	}
}

void bubble_sort_iterator( UnsignedIterator first, UnsignedIterator last) {
	bool swapped = true;
	UnsignedIterator it;
	while(swapped) {	
		swapped = false;
		it = first;
		--last;
		while(it != last) {
			if (*(it + 1) < *it ) {
				std::swap(*(it + 1), *it);
				swapped = true;
			}
			++it;
		}
	}
}

UnsignedIterator partition_iterator(UnsignedIterator first, UnsignedIterator last) {
	UnsignedIterator pivot = last-1;
	UnsignedIterator slow = first;
	UnsignedIterator fast = first;

	while(fast != last) {
		if (*fast < *pivot) {
			std::swap(*slow, *fast);
			++slow;
		}
	++fast;
	}
	std::swap(*slow, *pivot);
	return slow;
}

void quick_sort_iterator( UnsignedIterator first, UnsignedIterator last) {
	if (first < last) {
		UnsignedIterator pivot = partition_iterator(first, last);
		quick_sort_iterator(first, pivot);
		quick_sort_iterator(pivot + 1, last);
	}
}

void merge_iterator(UnsignedIterator first, UnsignedIterator last, UnsignedIterator mid) {
	ValueType size_total = std::distance(first, last);
	ValueType size_left = std::distance(first, mid);
	ValueType size_right = size_total - size_left;

	ValueType* left = new ValueType[size_left];
	ValueType* right = new ValueType[size_right];

	std::copy(first, mid, left);
	std::copy(mid, last, right);

	ValueType i = 0;
	ValueType j = 0;
	ValueType k = 0;

	while(i < size_left and j < size_right) {
		first[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
	}

	if(i < size_left){
		std::copy(left + i, left + size_left, first + k);
	}
	else{
		std::copy(right + j, right + size_right, first + k);
	}
	delete[] left;
	delete[] right;
}

void merge_sort_iterator(UnsignedIterator first, UnsignedIterator last) {
	ValueType distance = std::distance(first, last);
	if(!(distance < 2)) {		
		UnsignedIterator mid = first + distance/2;
		merge_sort_iterator(first, mid);
		merge_sort_iterator(mid, last);
		merge_iterator(first, last, mid);
	}
}

void shell_sort_iterator(UnsignedIterator first, UnsignedIterator last) {
	bool swapped = true;
	ValueType gap = std::distance(first, last);
	while(swapped or (gap > 1)) {
		swapped = false;
		gap = (gap + 1) / 2;
		for (ValueType i = 0; i < (std::distance(first, last) - gap); i++) {
			if (first[i + gap] < first[i]) {
				std::swap(first[i + gap], first[i]);
				swapped = true;
			}
		}
	}
}

ValueType range_max_iterator(UnsignedIterator first, UnsignedIterator last) {
	ValueType max = *first;
	while (first != last) {
		if (*first > max) {
			max = *first;
		}
		++first;
	}
	return max;
}

void radix_sort_iterator (UnsignedIterator first, UnsignedIterator last) {
	ValueType max = range_max_iterator(first, last);
	ValueType size = std::distance(first, last);
	ValueType *sorted;
	try {
		sorted = new ValueType [size];
	}
	catch(std::bad_alloc& ba) {
		std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
		std::cout << "Ocorreu um erro. Não é possivel continuar. " << std::endl;
		return;
	}

	for (int exp = 1; max / exp > 0; exp *= 10) { // Base Decimal
		ValueType count[10] = {0};
	 
		for (UnsignedIterator it = first; it != last; ++it) {
			count[(*it / exp) % 10]++;
		}
		for (int i = 1; i < 10; ++i) {
			count[i] += count[i - 1];
		}
		for (UnsignedIterator it = last - 1; it != first - 1; --it) {
			sorted[count[(*it / exp) % 10] - 1] = *it;
			count[(*it / exp) % 10]--;
		}

		std::copy(sorted, sorted + (size), first);
	}
	delete[] sorted;
}
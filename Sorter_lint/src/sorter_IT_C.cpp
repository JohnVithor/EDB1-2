// Copyright 2018 JV

/**
 * @file sorter_IT_iterator_steps.cpp
 * @brief      Arquivo com a implementação das funções de ordenação (Iterador)
 *             para a contagem do passos da operação dominante
 * @author     João Vítor Venceslau Coelho
 * @since      08/10/2017
 * @date       23/03/2018
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>
#include <utility>

#include "sorter_IT.hpp"
#include "sorter_IT_C.hpp"

using ValueType = unsigned int;
using UnsignedIterator = std::vector<ValueType>::iterator;

void insertion_sort_iterator_steps(UnsignedIterator first, UnsignedIterator last, ValueType &steps) {
    for (ValueType i = 1; i < std::distance(first, last); i++) {
        ValueType key = first[i];
        ValueType j = i - 1;
        /* Caso o ValueType seja alterado possa ser necessário adicionar a seguinte
        condição: j >= 0, pois valores negativos provavelmente serão possíveis */
        while (j != std::numeric_limits<ValueType>::max() && first[j] > key) {
            steps += 5;
            first[j + 1] = first[j];
            steps += 3;
            --j;
            ++steps;
        }
        first[j + 1] = key;
    }
}

void selection_sort_iterator_steps(UnsignedIterator first, UnsignedIterator last, ValueType &steps) {
    UnsignedIterator aux = first;
    while (first != last) {
        UnsignedIterator smaller = aux;
        while (aux != last) {
            ++steps;
            if (*aux < *smaller) {
                ++steps;
                smaller = aux;
                ++steps;
            }
            ++aux;
            ++steps;
        }
        std::swap(*first, *smaller);
        ++steps;
        ++first;
        aux = first;
    }
}

void bubble_sort_iterator_steps(UnsignedIterator first, UnsignedIterator last, ValueType &steps) {
    bool swapped = true;
    UnsignedIterator it;
    while (swapped) {
        swapped = false;
        it = first;
        --last;
        while (it != last) {
            ++steps;
            if (*(it + 1) < *it) {
                steps += 3;
                std::swap(*(it + 1), *it);
                steps += 3;
                steps += 2;
                swapped = true;
            }
            ++it;
        }
    }
}

UnsignedIterator partition_iterator_steps(UnsignedIterator first, UnsignedIterator last, ValueType &steps) {
    UnsignedIterator pivot = last - 1;
    UnsignedIterator slow = first;
    UnsignedIterator fast = first;

    while (fast != last) {
        ++steps;
        if (*fast < *pivot) {
            steps += 3;
            std::swap(*slow, *fast);
            steps += 3;
            steps += 2;
            ++slow;
            ++steps;
        }
    ++fast;
    ++steps;
    }
    std::swap(*slow, *pivot);
    steps += 3;
    steps += 2;
    return slow;
}

void quick_sort_iterator_steps(UnsignedIterator first, UnsignedIterator last, ValueType &steps) {
    if (first < last) {
        UnsignedIterator pivot = partition_iterator_steps(first, last, steps);
        quick_sort_iterator_steps(first, pivot, steps);
        quick_sort_iterator_steps(pivot + 1, last, steps);
    }
}

void merge_iterator_steps(UnsignedIterator first, UnsignedIterator last, UnsignedIterator mid, ValueType &steps) {
    ValueType size_total = std::distance(first, last);
    ValueType size_left = std::distance(first, mid);
    ValueType size_right = size_total - size_left;

    ValueType* left = new ValueType[size_left];
    ++steps;
    ValueType* right = new ValueType[size_right];
    ++steps;
    std::copy(first, mid, left);
    steps += size_left;
    std::copy(mid, last, right);
    steps += size_right;
    ValueType i = 0;
    ValueType j = 0;
    ValueType k = 0;

    while (i < size_left && j < size_right) {
        steps += 3;
        first[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
        steps += 5;
    }

    if (i < size_left) {
        std::copy(left+i, left+size_left, first+k);
        steps += size_left - i;
    } else {
        std::copy(right+j, right+size_right, first+k);
        steps += size_right - j;
    }
    delete[] left;
    ++steps;
    delete[] right;
    ++steps;
}

void merge_sort_iterator_steps(UnsignedIterator first, UnsignedIterator last, ValueType &steps) {
    size_t distance = std::distance(first, last);
    if (!(distance < 2)) {
        UnsignedIterator mid = first + distance / 2;
        merge_sort_iterator_steps(first, mid, steps);
        merge_sort_iterator_steps(mid, last, steps);
        merge_iterator_steps(first, last, mid, steps);
    }
}

void shell_sort_iterator_steps(UnsignedIterator first, UnsignedIterator last, ValueType &steps) {
    bool swapped = true;
    ValueType gap = std::distance(first, last);
    while (swapped || (gap > 1)) {
        swapped = false;
        gap = (gap + 1) / 2;
        for (ValueType i = 0; i < (std::distance(first, last) - gap); i++) {
            steps += 4;
            if (first[i + gap] < first[i]) {
                steps += 4;
                std::swap(first[i + gap], first[i]);
                steps += 3;
                steps += 2;
                swapped = true;
            }
        }
    }
}

void radix_sort_iterator_steps(UnsignedIterator first, UnsignedIterator last, ValueType &steps) {
    ValueType max = range_max_iterator(first, last);
    ValueType size = std::distance(first, last);
    ValueType *sorted;
    try {
        sorted = new ValueType[size];
    } catch(std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        std::cout << "Ocorreu um erro. Não é possivel continuar. " << std::endl;
        return;
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {  // Base Decimal
        ValueType count[10] = {0};
        ++steps;
        for (UnsignedIterator it = first; it != last; ++it) {
            steps += 3;
            count[(*it / exp) % 10]++;
            steps += 5;
        }
        for (int i = 1; i < 10; i++) {
            steps += 3;
            count[i] += count[i - 1];
            steps += 3;
        }
        for (UnsignedIterator it = last-1; it != first-1; --it) {
            steps += 3;
            sorted[count[(*it / exp) % 10] - 1] = *it;
            steps += 7;
            count[(*it / exp) % 10]--;
            steps += 5;
        }
        std::copy(sorted, sorted + (size), first);
    }
    delete[] sorted;
}

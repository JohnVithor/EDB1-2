// Copyright 2018 JV

/**
* @file     sorter_V_C.cpp
* @brief    Arquivo com a implementação das funções de ordenação (Vector)
*           para a contagem do passos da operação dominante
* @author   João Vítor Venceslau Coelho
* @since    08/10/2017
* @date     23/03/2018
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include "sorter_V.hpp"
#include "sorter_V_C.hpp"

using ValueType = unsigned int;
using UnsignedVector = std::vector<ValueType>;
using UnsignedIterator = std::vector<ValueType>::iterator;

void insertion_sort_vector_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    for (ValueType i = 1; i < right - left; i++) {
        ValueType key = vetor[i];
        ValueType j = i - 1;
        while (j >= left && j!= left - 1 && vetor[j] > key) {
            steps += 5;
            vetor[j + 1] = vetor[j];
            steps += 3;
            --j;
            ++steps;
        }
        vetor[j + 1] = key;
    }
}

void selection_sort_vector_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    ValueType aux = left;
    while (left != right) {
        ValueType smaller = aux;
        while (aux != right) {
            ++steps;
            if (vetor[aux] < vetor[smaller]) {
                ++steps;
                smaller = aux;
                ++steps;
            }
            ++aux;
            ++steps;
        }
        std::swap(vetor[left], vetor[smaller]);
        ++steps;
        ++left;
        aux = left;
    }
}

void bubble_sort_vector_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    bool swapped = true;
    ValueType it;
    while (swapped) {
        swapped = false;
        it = left;
        --right;
        while (it != right) {
            ++steps;
            if (vetor[it + 1] < vetor[it]) {
                steps += 3;
                std::swap(vetor[it + 1], vetor[it]);
                steps += 3;
                steps += 2;
                swapped = true;
            }
            ++it;
        }
    }
}

ValueType partition_vector_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    ValueType slow = left;
    ValueType fast = left;
    ValueType pivot = right;
    while (fast != right) {
            ++steps;
        if (vetor[fast] < vetor[pivot]) {
            steps += 3;
            std::swap(vetor[slow], vetor[fast]);
            steps += 3;
            steps += 2;
            ++slow;
            ++steps;
        }
    ++fast;
    ++steps;
    }
    std::swap(vetor[slow], vetor[pivot]);
    steps += 3;
    steps += 2;
    return slow;
}

void quick_sort_vector_internal_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    if (left < right) {
        ValueType pivot = partition_vector_steps(vetor, left, right, steps);
        if (pivot == 0) {
            quick_sort_vector_internal_steps(vetor, left, pivot, steps);
        } else {
            quick_sort_vector_internal_steps(vetor, left, pivot - 1, steps);
        }
        quick_sort_vector_internal_steps(vetor, pivot + 1, right, steps);
    } else {
        return;
    }
}

void quick_sort_vector_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    --right;
    quick_sort_vector_internal_steps(vetor, left, right, steps);
}

void merge_vector_steps(UnsignedVector &vetor, ValueType left, ValueType mid, ValueType right, ValueType &steps) {
    ValueType size_A = right - left + 1;
    ValueType size_L = mid - left + 1;
    ValueType size_R = size_A - size_L;

    ValueType* L_aux = new ValueType[size_L];
    ++steps;
    ValueType* R_aux = new ValueType[size_R];
    ++steps;
    std::copy(vetor.begin() + left, vetor.begin() + (mid + 1), L_aux);
    steps += size_L;
    std::copy(vetor.begin() + (mid + 1), vetor.begin() + (right + 1), R_aux);
    steps += size_R;

    ValueType i = 0;
    ValueType j = 0;
    ValueType k = left;

    while (i < size_L && j < size_R) {
        steps += 3;
        vetor[k++] = (L_aux[i] < R_aux[j]) ? L_aux[i++] : R_aux[j++];
        steps += 5;
    }

    if (i < size_L) {
        std::copy(L_aux + i, L_aux + size_L, vetor.begin() + k);
        steps += size_L - i;
    } else {
        std::copy(R_aux + j, R_aux + size_R, vetor.begin() + k);
        steps += size_R - i;
    }

    delete[] L_aux;
    ++steps;
    delete[] R_aux;
    ++steps;
}

void merge_sort_vector_internal_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    if (right > left) {
        ValueType mid = left + (right - left) / 2;
        merge_sort_vector_internal_steps(vetor, left, mid, steps);
        merge_sort_vector_internal_steps(vetor, mid + 1, right, steps);
        merge_vector_steps(vetor, left, mid, right, steps);
    }
}

void merge_sort_vector_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    --right;
    merge_sort_vector_internal_steps(vetor, left, right, steps);
}

void shell_sort_vector_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    bool swapped = true;
    ValueType gap = right-left;
    while (swapped || (gap > 1)) {
        swapped = false;
        gap = (gap + 1) / 2;
        for (ValueType i = 0; i < (right - left - gap); i++) {
            steps += 4;
            if (vetor[i + gap] < vetor[i]) {
                steps += 4;
                std::swap(vetor[i + gap], vetor[i]);
                steps += 3;
                steps += 2;
                swapped = true;
            }
        }
    }
}

void radix_sort_vector_steps(UnsignedVector &vetor, ValueType left, ValueType right, ValueType &steps) {
    ValueType max = range_max_vector(vetor, left, right);
    ValueType *sorted;
    try {
        sorted = new ValueType[right - left];
    } catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        std::cout << "Ocorreu um erro. Não é possivel continuar. " << std::endl;
        return;
    }
    for (int exp = 1; max/exp > 0; exp *= 10) {  // Base Decimal
        ValueType count[10] = {0};
        for (UnsignedIterator it = vetor.begin() + left; it != vetor.begin() + right; ++it) {
            steps += 3;
            count[ (*it / exp) % 10 ]++;
            steps += 5;
        }
        for (int i = 1; i < 10; i++) {
            steps += 3;
            count[i] += count[i - 1];
            steps += 3;
        }
        for (UnsignedIterator it = vetor.begin() + right - 1; it != vetor.begin() + left - 1; --it) {
            steps += 3;
            sorted[count[(*it / exp) % 10] - 1] = *it;
            steps += 7;
            count[(*it / exp) % 10]--;
            steps += 5;
        }
        std::copy(sorted, sorted + (right - left), vetor.begin() + left);
    }
    delete[] sorted;
}

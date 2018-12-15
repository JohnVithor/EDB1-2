// Copyright 2018 JV

/**
 * @file sorter_V.cpp
 * @brief      Arquivo com a implementação das funções de ordenação (Vector)
 * @author     João Vítor Venceslau Coelho
 * @since      23/09/2017
 * @date       23/03/2018
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include "sorter_V.hpp"

using ValueType = unsigned int;
using UnsignedVector = std::vector<ValueType>;
using UnsignedIterator = std::vector<ValueType>::iterator;

void insertion_sort_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    for (ValueType i = 1; i < right-left; i++) {
        ValueType key = vector[i];
        ValueType j = i - 1;
        while (j >= left && j!= left - 1 && vector[j] > key) {
            vector[j + 1] = vector[j];
            --j;
        }
        vector[j+1] = key;
    }
}

void selection_sort_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    ValueType aux = left;
    while (left != right) {
        ValueType smaller = aux;
        while (aux != right) {
            if (vector[aux] < vector[smaller]) {
                smaller = aux;
            }
            ++aux;
        }
        std::swap(vector[left], vector[smaller]);
        ++left;
        aux = left;
    }
}

void bubble_sort_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    bool swapped = true;
    ValueType it;
    while (swapped) {
        swapped = false;
        it = left;
        --right;
        while (it != right) {
            if (vector[it + 1] < vector[it]) {
                std::swap(vector[it + 1], vector[it]);
                swapped = true;
            }
            ++it;
        }
    }
}

ValueType partition_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    ValueType slow = left;
    ValueType fast = left;
    ValueType pivot = right;

    while (fast != right) {
        if (vector[fast] < vector[pivot]) {
            std::swap(vector[slow], vector[fast]);
            ++slow;
        }
    ++fast;
    }
    std::swap(vector[slow], vector[pivot]);
    return slow;
}

void quick_sort_vector_internal(UnsignedVector &vector, ValueType left, ValueType right) {
    if (left < right) {
        ValueType pivot = partition_vector(vector, left, right);
        if (pivot == 0) {
            quick_sort_vector_internal(vector, left, pivot);
        } else {
            quick_sort_vector_internal(vector, left, pivot - 1);
        }
        quick_sort_vector_internal(vector, pivot + 1, right);
    } else {
        return;
    }
}


void quick_sort_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    --right;
    quick_sort_vector_internal(vector, left, right);
}

void merge_vector(UnsignedVector &vector, ValueType left, ValueType mid, ValueType right) {
    ValueType size_A = right - left + 1;
    ValueType size_L = mid - left + 1;
    ValueType size_R = size_A - size_L;

    ValueType* L_aux = new ValueType[size_L];
    ValueType* R_aux = new ValueType[size_R];

    std::copy(vector.begin() + left , vector.begin() + (mid + 1), L_aux);
    std::copy(vector.begin() + (mid + 1), vector.begin() + (right + 1), R_aux);

    ValueType i = 0;
    ValueType j = 0;
    ValueType k = left;

    while (i < size_L && j < size_R) {
        vector[k++] = (L_aux[i] < R_aux[j]) ? L_aux[i++] : R_aux[j++];
    }

    if (i < size_L) {
        std::copy(L_aux + i, L_aux+size_L, vector.begin() + k);
    } else {
        std::copy(R_aux + j, R_aux+size_R, vector.begin() + k);
    }

    delete[] L_aux;
    delete[] R_aux;
}

void merge_sort_vector_internal(UnsignedVector &vector, ValueType left, ValueType right) {
    if (right > left) {
        ValueType mid = left + (right - left) / 2;
        merge_sort_vector_internal(vector, left, mid);
        merge_sort_vector_internal(vector, mid + 1, right);
        merge_vector(vector, left, mid, right);
    }
}

void merge_sort_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    --right;
    merge_sort_vector_internal(vector, left, right);
}

void shell_sort_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    bool swapped = true;
    ValueType gap = right - left;
    while (swapped || (gap > 1)) {
        swapped = false;
        gap = (gap + 1) / 2;
        for (ValueType i = 0; i < (right - left - gap); i++) {
            if (vector[i + gap] < vector[i]) {
                std::swap(vector[i + gap], vector[i]);
                swapped = true;
            }
        }
    }
}

ValueType range_max_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    ValueType max = vector[0];
    for (ValueType i = left; i >= right; ++i) {
        if (vector[i] > max) {
            max = vector[i];
        }
    }
    return max;
}

void radix_sort_vector(UnsignedVector &vector, ValueType left, ValueType right) {
    ValueType max = range_max_vector(vector, left, right);
    ValueType *sorted;
    try {
        sorted = new ValueType[right - left];
    } catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
        std::cout << "Ocorreu um erro. Não é possivel continuar. " << std::endl;
        return;
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {  // Base Decimal
        ValueType count[10] = {0};
        for (UnsignedIterator it = vector.begin() + left; it != vector.begin() + right; ++it) {
            count[ (*it / exp) % 10 ]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (UnsignedIterator it = vector.begin() + right - 1; it != vector.begin() + left - 1; --it) {
            sorted[count[(*it / exp) % 10] - 1] = *it;
            count[(*it / exp) % 10]--;
        }
        std::copy(sorted, sorted + (right - left), vector.begin() + left);
    }
    delete[] sorted;
}

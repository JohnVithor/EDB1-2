// Copyright 2018 JV

/**
 * @file HeapMax.inl
 * @brief      Implementação da Classe HeapMax, seus atributos e
 * métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      12/05/2018
 * @date       14/05/2018
 */

#include "HeapMax.hpp"

template <typename T>
HeapMax<T>::HeapMax() {
  heap = new T[10];
  m_capacity = 10;
  number_elements = 0;
}

template <typename T>
HeapMax<T>::HeapMax(std::initializer_list<T> ilist) {
  number_elements = ilist.size();
  heap = new T[number_elements+1];
  int j = 1;
  for (auto it = ilist.begin(); it != ilist.end(); ++it) {
    heap[j] = *it;
    ++j;
  } 
  for (int i = number_elements / 2; i > 0; --i) {
    down(i);
  }
}

template <typename T>
HeapMax<T>::~HeapMax() {
  // delete heap;
}

template <typename T>
T& HeapMax<T>::getRoot() {
  return heap[1];
}

template <typename T>
int HeapMax<T>::getUp(int pos) {
  if (pos > 0 && pos <= number_elements) {
    return pos / 2;
  }
  return -1;
}

template <typename T>
int HeapMax<T>::getLeft(int pos) {
  int left = 2 * pos;
  if (left <= number_elements) {
    return left;
  }
  return -1;
}

template <typename T>
int HeapMax<T>::getRight(int pos) {
  int right = (2 * pos) + 1;
  if (right <= number_elements) {
    return right;
  }
  return -1;
}

template <typename T>
int HeapMax<T>::size() {
  return number_elements;
}

template <typename T>
int HeapMax<T>::capacity() {
  return this->m_capacity;
}

template <typename T>
bool HeapMax<T>::down(int pos) {
  if (pos > 0 && pos <= number_elements) {
    int left = getLeft(pos);
    if (left > 0) {
      if (left <= number_elements) {
        if (left + 1 <= number_elements) {
          if (heap[left + 1] > heap[left]) {
            left = left + 1;
          }
        }
        if (heap[pos] < heap[left]) {
          std::swap(heap[pos], heap[left]);
          down(left);
        }
        return true;
      }
    }
  }
  return false;
}

template <typename T>
bool HeapMax<T>::remove(int pos) {
  if (pos > 0 && number_elements > 0 && pos <= number_elements) {
    heap[pos] = heap[number_elements - 1];
    --number_elements;
    down(pos);
    heap->pop_back();
    return true;
  }
  return false;
}

template <typename T>
bool HeapMax<T>::up(int pos) {
  if (pos > 0 && pos <= number_elements) {
    int dad = getUp(pos);
    if (dad > 0) {
      if (heap[pos] > heap[dad]) {
        std::swap(heap[pos], heap[dad]);
        up(dad);
      }
    }
    return true;
  }
  return false;
}

template <typename T>
void HeapMax<T>::growCapacity(int value) {
  try {
    T* oldHeap = heap;
    heap = new T[m_capacity + value];
    for (int i = 1; i <= number_elements; ++i) {
      heap[i] = oldHeap[i];
    }
    m_capacity = m_capacity + value;
    // delete oldHeap;
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

template <typename T>
bool HeapMax<T>::insert(T value) {
  try {
    if (number_elements + 1 >= m_capacity) {
      growCapacity(10);
    }
    heap[number_elements] = value;
    ++number_elements;
    up(number_elements - 1);
    return true;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return false;
  }
}

template <typename T>
bool HeapMax<T>::changePriority(int pos, T* newValue) {
  if (pos <= number_elements && pos > 0) {
    T old = heap[pos];
    heap[pos] = *newValue;
    if (old < *newValue) {
      up(pos);
    } else {
      down(pos);
    }
    return true;
  }
  return false;
}

template <typename T>
void HeapMax<T>::print() {
  for (int i = 1; i <= number_elements; ++i) {
    std::cout << heap[i] << " ";
  }
  std::cout << std::endl;
  for (int i = 1; i <= number_elements; ++i) {
    print(i);
  }
}

template <typename T>
void HeapMax<T>::print(int pos) {
  int left = -1;
  int right = -1;
  if (pos < number_elements) {
    left = getLeft(pos);
    right = getRight(pos);
    std::cout << "Data: " << heap[pos];
  }
  if (left > 0) {
    std::cout << " left: " << heap[left];
  }
  if (right > 0) {
    std::cout << " right: " << heap[right];
  }
  std::cout << std::endl;
}

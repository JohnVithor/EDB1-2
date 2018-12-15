// Copyright 2018 JV

/**
 * @file HeapMax.hpp
 * @brief      Declaração da Classe HeapMax, seus atributos e métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      12/05/2018
 * @date       14/05/2018
 */

#ifndef HEAP_INCLUDE_HEAPMAX_HPP_
#define HEAP_INCLUDE_HEAPMAX_HPP_

#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class HeapMax {
 private:
  T *heap;
  int number_elements;
  int m_capacity;
  int getUp(int pos);
  int getLeft(int pos);
  int getRight(int pos);
  void growCapacity(int value);

 public:
  HeapMax();
  explicit HeapMax(std::initializer_list<T> ilist);
  HeapMax(HeapMax &&) = default;
  HeapMax(const HeapMax &) = default;
  HeapMax &operator=(HeapMax &&) = default;
  HeapMax &operator=(const HeapMax &) = default;
  ~HeapMax();

  T &getRoot();

  int size();
  int capacity();

  bool down(int pos);
  bool remove(int pos);
  bool up(int pos);
  bool insert(T value);
  bool changePriority(int pos, T *newValue);
  void print();
  void print(int pos);
};

#include "HeapMax.inl"
#endif  // HEAP_INCLUDE_HEAPMAX_HPP_

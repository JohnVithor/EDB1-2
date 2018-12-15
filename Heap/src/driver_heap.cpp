// Copyright 2018 JV

/**
 * @file driver_heap.cpp
 * @brief      Testes das classes de heap
 *
 * @author     João Vítor Venceslau Coelho
 * @since      12/05/2018
 * @date       12/05/2018
 */

#include <iostream>
#include "HeapMax.hpp"

int main(int argc, char** argv) {
  // {40, 30, 31, 9, 10, 20, 11, 0, 7, 3, 6, 2, 4, 5}
  HeapMax<int> heap({0, 10, 20, 30, 40, 4, 5, 9, 7, 3, 6, 2, 31, 11});
  heap.print();
  heap.insert(15);
  heap.print();
  return 0;
}

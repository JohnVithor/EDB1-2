// Copyright 2018 JV

/**
 * @file driverAVLTree.cpp
 * @brief      Testes da classe AVLTree
 *
 * @author     João Vítor Venceslau Coelho
 * @since      31/05/2018
 * @date       31/05/2018
 */

#include <iostream>
#include "AVLTree.hpp"

template <typename T>
void print(JV::Nodeptr<T> node) {
  std::cout << "Data: " << node->getData();
  JV::Nodeptr<T> left = node->getLeft();
  JV::Nodeptr<T> right = node->getRight();
  if (left != nullptr) {
    std::cout << " Left: " << left->getData();
  }
  if (right != nullptr) {
    std::cout << " Right: " << right->getData();
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) { return 0; }

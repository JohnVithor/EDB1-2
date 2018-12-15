// Copyright 2018 JV

/**
 * @file driverBinarySearchTree.cpp
 * @brief      Testes da classe BinarySearchTree
 *
 * @author     João Vítor Venceslau Coelho
 * @since      31/05/2018
 * @date       31/05/2018
 */

#include <iostream>
#include "BinarySearchTree.hpp"

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

int main(int argc, char** argv) {
  JV::BinarySearchTree<int> tree;
  std::cout << "Apenas a Raiz:" << std::endl;
  tree.insert(8);
  tree.inLevel(print);
  std::cout << "Raiz com todos os filhos:" << std::endl;
  tree.insert(4);
  tree.insert(16);
  tree.inLevel(print);
  std::cout << "Raiz com todos os netos:" << std::endl;
  tree.insert(2);
  tree.insert(6);
  tree.insert(10);
  tree.insert(12);
  tree.inLevel(print);
  std::cout << "Apagar a raiz:" << std::endl;
  tree.remove(8);
  tree.inLevel(print);
  return 0;
}

// Copyright 2018 JV

/**
 * @file driverBinaryNode.cpp
 * @brief      Testes da classe BinaryNode
 *
 * @author     João Vítor Venceslau Coelho
 * @since      31/05/2018
 * @date       31/05/2018
 */

#include <iostream>
#include "BinaryNode.hpp"

using T = int;
using Node = JV::BinaryNode<T>;
using Nodeptr = std::shared_ptr<Node>;

int main(int argc, char** argv) {
  {
    T t = T();
    Node node1(t);
    T data = node1.getData();
    std::cout << "Data: " << data << std::endl;
    std::cout << node1 << std::endl;
  }
  {
    T t = T();
    Nodeptr node1(new Node(t));
    std::cout << *node1 << std::endl;
    Nodeptr node2(new Node(t, node1));
    std::cout << *node2 << std::endl;
    Nodeptr node3(new Node(t, node1, node1));
    std::cout << *node3 << std::endl;
    Nodeptr node4(new Node(t, node1, node1, node1));
    std::cout << *node4 << std::endl;
  }
  // TODO(JohnVithor): Mais testes...
  return 0;
}

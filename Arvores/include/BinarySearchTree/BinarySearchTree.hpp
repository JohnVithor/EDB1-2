// Copyright 2018 JV

/**
 * @file BinarySearchTree.hpp
 * @brief      Declaração da Classe BinarySearchTree, seus atributos e métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      25/04/2018
 * @date       31/04/2018
 */

#ifndef ARVORES_INCLUDE_BINARYSEARCHTREE_BINARYSEARCHTREE_HPP_
#define ARVORES_INCLUDE_BINARYSEARCHTREE_BINARYSEARCHTREE_HPP_

#include "BinaryTree.hpp"

namespace JV {

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
 public:
  explicit BinarySearchTree(Nodeptr<T> root = nullptr);
  BinarySearchTree(BinarySearchTree &&) = default;
  BinarySearchTree(const BinarySearchTree &) = default;
  BinarySearchTree &operator=(BinarySearchTree &&) = default;
  BinarySearchTree &operator=(const BinarySearchTree &) = default;
  ~BinarySearchTree();

  Nodeptr<T> search(const T &target);
  bool insert(const T &target);
  bool insert(Nodeptr<T> node, const T &target);
  bool remove(const T &target);
  bool remove(Nodeptr<T> node, const T &target);

  Nodeptr<T> maximum(Nodeptr<T> node);
  Nodeptr<T> minimum(Nodeptr<T> node);
};
}  // namespace JV

#include "BinarySearchTree.inl"
#endif  // ARVORES_INCLUDE_BINARYSEARCHTREE_BINARYSEARCHTREE_HPP_

// Copyright 2018 JV

/**
 * @file AVLTree.hpp
 * @brief      Declaração da Classe AVLTree, seus atributos e métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      31/05/2018
 * @date       31/05/2018
 */

#ifndef ARVORES_INCLUDE_AVLTREE_AVLTREE_HPP_
#define ARVORES_INCLUDE_AVLTREE_AVLTREE_HPP_

#include "BinarySearchTree.hpp"
namespace JV {
template <typename T>
class AVLTree : BinarySearchTree<T> {
 public:
  explicit AVLTree(BinaryNode<T> *root = nullptr);
  AVLTree(AVLTree &&) = default;
  AVLTree(const AVLTree &) = default;
  AVLTree &operator=(AVLTree &&) = default;
  AVLTree &operator=(const AVLTree &) = default;
  ~AVLTree();

  // TODO(johnvithor):
};
}  // namespace JV
#include "AVLTree.inl"
#endif  // ARVORES_INCLUDE_AVLTREE_AVLTREE_HPP_

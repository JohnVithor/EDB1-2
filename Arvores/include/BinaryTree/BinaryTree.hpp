// Copyright 2018 JV

/**
 * @file BinaryTree.hpp
 * @brief      Declaração da Classe BinaryTree, seus atributos e métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      22/04/2018
 * @date       31/05/2018
 */

#ifndef ARVORES_INCLUDE_BINARYTREE_BINARYTREE_HPP_
#define ARVORES_INCLUDE_BINARYTREE_BINARYTREE_HPP_

#include "BinaryNode.hpp"

namespace JV {

template <typename T>
using LookUpFunction = void (*)(Nodeptr<T>);

template <typename T>
class BinaryTree {
 protected:
  Nodeptr<T> root;
  int size;
  void recursiveErase(Nodeptr<T> node);
  void updateParent(Nodeptr<T> node1, Nodeptr<T> node2);
  void substitute(Nodeptr<T> first, Nodeptr<T> second);

 public:
  explicit BinaryTree(Nodeptr<T> root = nullptr);
  BinaryTree(BinaryTree &&) = default;
  BinaryTree(const BinaryTree &) = default;
  BinaryTree &operator=(BinaryTree &&) = default;
  BinaryTree &operator=(const BinaryTree &) = default;
  ~BinaryTree();

  void preOrderR(Nodeptr<T> target, LookUpFunction<T> lookUp);
  void preOrderR(LookUpFunction<T> lookUp);
  void preOrderI(Nodeptr<T> target, LookUpFunction<T> lookUp);
  void preOrderI(LookUpFunction<T> lookUp);

  void inOrderR(Nodeptr<T> target, LookUpFunction<T> lookUp);
  void inOrderR(LookUpFunction<T> lookUp);
  void inOrderI(Nodeptr<T> target, LookUpFunction<T> lookUp);
  void inOrderI(LookUpFunction<T> lookUp);

  void postOrderR(Nodeptr<T> target, LookUpFunction<T> lookUp);
  void postOrderR(LookUpFunction<T> lookUp);
  void postOrderI(Nodeptr<T> target, LookUpFunction<T> lookUp);
  void postOrderI(LookUpFunction<T> lookUp);

  void inLevel(Nodeptr<T> target, LookUpFunction<T> lookUp);
  void inLevel(LookUpFunction<T> lookUp);

  Nodeptr<T> last();

  Nodeptr<T> search(const T &target);
  bool insert(const T &target);
  bool remove(const T &target);
};
}  // namespace JV

#include "BinaryTree.inl"

#endif  // ARVORES_INCLUDE_BINARYTREE_BINARYTREE_HPP_

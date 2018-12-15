// Copyright 2018 JV

/**
 * @file BinaryNode.hpp
 * @brief      Declaração da Classe BinaryNode, seus atributos e métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      22/04/2018
 * @date       31/05/2018
 */

#ifndef ARVORES_INCLUDE_BINARYNODE_BINARYNODE_HPP_
#define ARVORES_INCLUDE_BINARYNODE_BINARYNODE_HPP_

#include <iostream>
#include <memory>

namespace JV {

template <typename T>
class BinaryNode;

template <typename T>
using Nodeptr = std::shared_ptr<BinaryNode<T>>;

template <typename T>
class BinaryNode {
 private:
  std::unique_ptr<T> data;
  Nodeptr<T> parent;
  Nodeptr<T> left;
  Nodeptr<T> right;

 public:
  explicit BinaryNode(const T& d, Nodeptr<T> p = nullptr,
                      Nodeptr<T> l = nullptr, Nodeptr<T> r = nullptr);

  explicit BinaryNode(std::unique_ptr<T> d = nullptr, Nodeptr<T> p = nullptr,
                      Nodeptr<T> l = nullptr, Nodeptr<T> r = nullptr);

  BinaryNode(BinaryNode&&) = default;
  BinaryNode(const BinaryNode&) = default;
  BinaryNode& operator=(BinaryNode&&) = default;
  BinaryNode& operator=(const BinaryNode&) = default;
  ~BinaryNode();

  std::unique_ptr<T> getDataPointer();
  const T& getData();
  Nodeptr<T> getParent();
  Nodeptr<T> getLeft();
  Nodeptr<T> getRight();

  void setParent(Nodeptr<T> newParent);
  void setParent(BinaryNode<T>* newParent);

  void setData(std::unique_ptr<T> newData);
  void setData(const T& newData);

  void setLeft(Nodeptr<T> newLeft);
  void setLeft(BinaryNode<T>* newLeft);

  void setRight(Nodeptr<T> newRight);
  void setRight(BinaryNode<T>* newRight);

  friend std::ostream& operator<<(std::ostream& o, BinaryNode<T>& node) {
    o << "Data: " << node.getData();
    o << " Parent: ";
    if (node.getParent() != nullptr) {
      o << node.getParent()->getData();
    } else {
      o << "nullptr";
    }
    o << " Left: ";
    if (node.getLeft() != nullptr) {
      o << node.getLeft()->getData();
    } else {
      o << "nullptr";
    }
    o << " Right: ";
    if (node.getRight() != nullptr) {
      o << node.getRight()->getData();
    } else {
      o << "nullptr";
    }
    return o;
  }
};
}  // namespace JV

#include "BinaryNode.inl"

#endif  // ARVORES_INCLUDE_BINARYNODE_BINARYNODE_HPP_

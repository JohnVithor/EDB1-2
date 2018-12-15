// Copyright 2018 JV

/**
 * @file BinaryNode.inl
 * @brief      Implementação da Classe BinaryNode, seus atributos e métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      22/04/2018
 * @date       31/05/2018
 */
namespace JV {

template <typename T>
BinaryNode<T>::BinaryNode(const T& d, Nodeptr<T> p, Nodeptr<T> l, Nodeptr<T> r)
    : data(new T(d)), parent(p), left(l), right(r) { /*Empty*/
}

template <typename T>
BinaryNode<T>::BinaryNode(std::unique_ptr<T> d, Nodeptr<T> p, Nodeptr<T> l,
                          Nodeptr<T> r)
    : data(d), parent(p), left(l), right(r) { /*Empty*/
}

template <typename T>
BinaryNode<T>::~BinaryNode() {
  data.reset();
  parent.reset();
  left.reset();
  right.reset();
}

template <typename T>
std::unique_ptr<T> BinaryNode<T>::getDataPointer() {
  return this->data;
}

template <typename T>
const T& BinaryNode<T>::getData() {
  return *(this->data);
}

template <typename T>
Nodeptr<T> BinaryNode<T>::getRight() {
  return this->right;
}

template <typename T>
Nodeptr<T> BinaryNode<T>::getParent() {
  return this->parent;
}

template <typename T>
Nodeptr<T> BinaryNode<T>::getLeft() {
  return this->left;
}

template <typename T>
void BinaryNode<T>::setData(std::unique_ptr<T> newData) {
  this->data.swap(newData);
}

template <typename T>
void BinaryNode<T>::setData(const T& newData) {
  this->data = std::make_unique<T>(newData);
}

template <typename T>
void BinaryNode<T>::setParent(Nodeptr<T> newParent) {
  this->parent = newParent;
}

template <typename T>
void BinaryNode<T>::setParent(BinaryNode<T>* newParent) {
  this->parent = std::shared_ptr<BinaryNode<T>>(newParent);
}

template <typename T>
void BinaryNode<T>::setLeft(Nodeptr<T> newLeft) {
  this->left = newLeft;
}

template <typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* newLeft) {
  this->left = std::shared_ptr<BinaryNode<T>>(newLeft);
}

template <typename T>
void BinaryNode<T>::setRight(Nodeptr<T> newRight) {
  this->right = newRight;
}

template <typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* newRight) {
  this->right = std::shared_ptr<BinaryNode<T>>(newRight);
}
}  // namespace JV
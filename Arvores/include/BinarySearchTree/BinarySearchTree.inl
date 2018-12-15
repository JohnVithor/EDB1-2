// Copyright 2018 JV

/**
 * @file BinarySearchTree.inl
 * @brief      Implementação da Classe BinarySearchTree, seus atributos e
 * métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      25/04/2018
 * @date       31/05/2018
 */
namespace JV {

template <typename T>
BinarySearchTree<T>::BinarySearchTree(Nodeptr<T> root)
    : BinaryTree<T>(root) { /*Empty*/
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {}

template <typename T>
Nodeptr<T> BinarySearchTree<T>::search(const T& target) {
  Nodeptr<T> current = this->root;
  T data = T();
  while (current != nullptr) {
    data = *(current->getData());
    if (data == target) {
      return current;
    }
    if (data < target) {
      current = current->getRight();
    } else {
      current = current->getLeft();
    }
  }
  return nullptr;
}

template <typename T>
bool BinarySearchTree<T>::insert(const T& target) {
  if (this->root == nullptr) {
    this->root = Nodeptr<T>(new BinaryNode<T>(target));
    this->size = 1;
    return true;
  }
  return insert(this->root, target);
}

template <typename T>
bool BinarySearchTree<T>::insert(Nodeptr<T> node, const T& target) {
  T data = node->getData();
  if (data != target) {
    if (data < target) {
      if (node->getRight() == nullptr) {
        node->setRight(new BinaryNode<T>(target, node));
        ++this->size;
        return true;
      }
      if (insert(node->getRight(), target)) {
        return true;
      }
    } else {
      if (node->getLeft() == nullptr) {
        node->setLeft(new BinaryNode<T>(target, node));
        ++this->size;
        return true;
      }
      if (insert(node->getLeft(), target)) {
        return true;
      }
    }
  }
  return false;
}

template <typename T>
bool BinarySearchTree<T>::remove(const T& target) {
  return remove(this->root, target);
}

template <typename T>
bool BinarySearchTree<T>::remove(Nodeptr<T> node, const T& target) {
  if (node != nullptr) {
    int data = node->getData();
    if (data == target) {
      if (node->getLeft() == nullptr && node->getRight() == nullptr) {
        this->updateParent(node, nullptr);
        node.reset();
        --this->size;
        return true;
      }
      if (node->getLeft() == nullptr) {
        this->updateParent(node, node->getRight());
        node->getRight()->setParent(node->getParent());
        node.reset();
        --this->size;
        return true;
      }
      if (node->getRight() == nullptr) {
        this->updateParent(node, node->getLeft());
        node->getLeft()->setParent(node->getParent());
        node.reset();
        --this->size;
        return true;
      }
      Nodeptr<T> smallest = minimum(node->getRight());
      if (smallest->getRight() != nullptr) {
        this->updateParent(smallest, smallest->getRight());
        smallest->getRight()->setParent(smallest->getParent());
      }
      this->substitute(node, smallest);
      this->updateParent(smallest, nullptr);
      smallest.reset();
      --this->size;
      return true;
    }
    if (data < target) {
      if (remove(node->getRight(), target)) {
        return true;
      }
    } else {
      if (remove(node->getLeft(), target)) {
        return true;
      }
    }
  }
  return false;
}

template <typename T>
Nodeptr<T> BinarySearchTree<T>::maximum(Nodeptr<T> node) {
  Nodeptr<T> step = node;
  if (node == nullptr) {
    step = this->root;
  }
  Nodeptr<T> biggest = step;
  while (step != nullptr) {
    biggest = step;
    step = step->getRight();
  }
  return biggest;
}

template <typename T>
Nodeptr<T> BinarySearchTree<T>::minimum(Nodeptr<T> node) {
  Nodeptr<T> step = node;
  if (node == nullptr) {
    step = this->root;
  }
  Nodeptr<T> smallest = step;
  while (step != nullptr) {
    smallest = step;
    step = step->getLeft();
  }
  return smallest;
}
}  // namespace JV
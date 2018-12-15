// Copyright 2018 JV

/**
 * @file BinaryTree.inl
 * @brief      Implementação da Classe BinaryTree, seus atributos e métodos.
 *
 * @author     João Vítor Venceslau Coelho
 * @since      22/04/2018
 * @date       31/05/2018
 */

#include <queue>
#include <stack>

namespace JV {

template <typename T>
BinaryTree<T>::BinaryTree(Nodeptr<T> r) : root(r) {
  if (root == nullptr) {
    size = 0;
    return;
  }
  size = 1;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
  recursiveErase(root);
}

template <typename T>
void BinaryTree<T>::recursiveErase(Nodeptr<T> node) {
  if (node != nullptr) {
    Nodeptr<T> left = node->getLeft();
    Nodeptr<T> right = node->getRight();
    node->setParent(nullptr);
    node->setLeft(nullptr);
    node->setRight(nullptr);
    node->setData(nullptr);
    recursiveErase(left);
    recursiveErase(right);
  }
}

template <typename T>
void BinaryTree<T>::preOrderR(Nodeptr<T> target, LookUpFunction<T> lookUp) {
  lookUp(target);
  if (target->getLeft() != nullptr) {
    preOrderR(target->getLeft(), lookUp);
  }
  if (target->getRight() != nullptr) {
    preOrderR(target->getRight(), lookUp);
  }
}

template <typename T>
void BinaryTree<T>::preOrderR(LookUpFunction<T> lookUp) {
  this->preOrderR(this->root, lookUp);
}

template <typename T>
void BinaryTree<T>::preOrderI(Nodeptr<T> target, LookUpFunction<T> lookUp) {
  std::stack<Nodeptr<T>> nodes;
  bool end = false;
  Nodeptr<T> node = target;
  do {
    if (node != nullptr) {
      lookUp(node);
      Nodeptr<T> aux = node->getRight();
      if (aux != nullptr) {
        nodes.push(aux);
        node = node->getLeft();
      } else if (node->getLeft() != nullptr) {
        node = node->getLeft();
      } else if (nodes.empty()) {
        end = true;
      } else {
        node = nodes.top();
        nodes.pop();
      }
    } else {
      node = nodes.top();
      nodes.pop();
    }
  } while (!end);
}

template <typename T>
void BinaryTree<T>::preOrderI(LookUpFunction<T> lookUp) {
  this->preOrderI(this->root, lookUp);
}

template <typename T>
void BinaryTree<T>::inOrderR(Nodeptr<T> target, LookUpFunction<T> lookUp) {
  if (target->getLeft() != nullptr) {
    inOrderR(target->getLeft(), lookUp);
  }
  lookUp(target);
  if (target->getRight() != nullptr) {
    inOrderR(target->getRight(), lookUp);
  }
}

template <typename T>
void BinaryTree<T>::inOrderR(LookUpFunction<T> lookUp) {
  this->inOrderR(this->root, lookUp);
}

template <typename T>
void BinaryTree<T>::inOrderI(Nodeptr<T> target, LookUpFunction<T> lookUp) {
  std::stack<Nodeptr<T>> nodes;
  bool end = false;
  Nodeptr<T> node = target;
  do {
    if (node != nullptr) {
      nodes.push(node);
      node = node->getLeft();
    } else if (!nodes.empty()) {
      node = nodes.top();
      nodes.pop();
      lookUp(node);
      node = node->getRight();
    } else {
      end = true;
    }
  } while (!end);
}

template <typename T>
void BinaryTree<T>::inOrderI(LookUpFunction<T> lookUp) {
  this->inOrderI(this->root, lookUp);
}

template <typename T>
void BinaryTree<T>::postOrderR(Nodeptr<T> target, LookUpFunction<T> lookUp) {
  if (target->getLeft() != nullptr) {
    postOrderR(target->getLeft(), lookUp);
  }
  if (target->getRight() != nullptr) {
    postOrderR(target->getRight(), lookUp);
  }
  lookUp(target);
}

template <typename T>
void BinaryTree<T>::postOrderR(LookUpFunction<T> lookUp) {
  this->postOrderR(this->root, lookUp);
}

template <typename T>
void BinaryTree<T>::postOrderI(Nodeptr<T> target, LookUpFunction<T> lookUp) {
  std::stack<std::pair<Nodeptr<T>, int>> nodes;
  Nodeptr<T> node = target;
  do {
    if (node != nullptr) {
      nodes.push(std::make_pair(node, 1));
      node = node->getLeft();
    } else if (!nodes.empty()) {
      std::pair<Nodeptr<T>, int> aux = nodes.top();
      nodes.pop();
      switch (aux.second) {
        case 1:
          nodes.push(std::make_pair(aux.first, 2));
          node = aux.first->getRight();
          break;
        case 2:
          lookUp(aux.first);
          break;
      }
    }
  } while (!nodes.empty());
}

template <typename T>
void BinaryTree<T>::postOrderI(LookUpFunction<T> lookUp) {
  this->postOrderI(this->root, lookUp);
}

template <typename T>
void BinaryTree<T>::inLevel(Nodeptr<T> target, LookUpFunction<T> lookUp) {
  std::queue<Nodeptr<T>> nodes;
  Nodeptr<T> node = target;
  nodes.push(node);
  while (!nodes.empty()) {
    node = nodes.front();
    nodes.pop();
    lookUp(node);
    if (node->getLeft() != nullptr) {
      nodes.push(node->getLeft());
    }
    if (node->getRight() != nullptr) {
      nodes.push(node->getRight());
    }
  }
}

template <typename T>
void BinaryTree<T>::inLevel(LookUpFunction<T> lookUp) {
  this->inLevel(this->root, lookUp);
}

template <typename T>
Nodeptr<T> BinaryTree<T>::search(const T& target) {
  std::stack<Nodeptr<T>> nodes;
  bool end = false;
  Nodeptr<T> node = target;
  do {
    if (node != nullptr) {
      if (*(node->getData()) == target) {
        return node;
      }
      Nodeptr<T> aux = node->getLeft();
      if (aux != nullptr) {
        nodes.push(aux);
        node = node->getRight();
      } else if (nodes.empty()) {
        end = true;
      } else {
        node = nodes.top();
        nodes.pop();
      }
    }
  } while (!end);
}

template <typename T>
bool BinaryTree<T>::insert(const T& target) {
  if (root == nullptr) {
    root = Nodeptr<T>(new BinaryNode<T>(target));
    return true;
  }
  std::queue<Nodeptr<T>> nodes;
  nodes.push(root);
  Nodeptr<T> node;
  while (!nodes.empty()) {
    node = nodes.front();
    nodes.pop();
    if (node->getData() == target) {
      return false;
    }
    if (node->getLeft() != nullptr) {
      nodes.push(node->getLeft());
    } else {
      node->setLeft(Nodeptr<T>(new BinaryNode<T>(target, node)));
      return true;
    }
    if (node->getRight() != nullptr) {
      nodes.push(node->getRight());
    } else {
      node->setRight(Nodeptr<T>(new BinaryNode<T>(target, node)));
      return true;
    }
  }
  return true;
}

template <typename T>
void BinaryTree<T>::substitute(Nodeptr<T> first, Nodeptr<T> second) {
  T data = first->getData();
  first->setData(second->getData());
  second->setData(data);
}

template <typename T>
void BinaryTree<T>::updateParent(Nodeptr<T> node1, Nodeptr<T> node2) {
  if (node1 == root) {
    root = node2;
    return;
  }
  if (node1->getParent()->getLeft() == node1) {
    node1->getParent()->setLeft(node2);
  } else {
    node1->getParent()->setRight(node2);
  }
}

template <typename T>
Nodeptr<T> BinaryTree<T>::last() {
  Nodeptr<T> current = root;
  while (current->getLeft() != nullptr || current->getRight() != nullptr) {
    if (current->getRight() != nullptr) {
      current = current->getRight();
    } else if (current->getLeft() != nullptr) {
      current = current->getRight();
    }
  }
  return current;
}

template <typename T>
bool BinaryTree<T>::remove(const T& target) {
  if (root == nullptr) {
    return false;
  }
  std::queue<Nodeptr<T>> nodes;
  nodes.push(root);
  Nodeptr<T> node;
  while (!nodes.empty()) {
    node = nodes.front();
    nodes.pop();
    if (node->getData() == target) {
      if (node->getLeft() == nullptr && node->getRight() == nullptr) {
        updateParent(node, nullptr);
        node.reset();
        --size;
        return true;
      }
      if (node->getLeft() == nullptr) {
        updateParent(node, node->getRight());
        node->getRight()->setParent(node->getParent());
        node.reset();
        --size;
        return true;
      }
      if (node->getRight() == nullptr) {
        updateParent(node, node->getLeft());
        node->getLeft()->setParent(node->getParent());
        node.reset();
        --size;
        return true;
      }
      Nodeptr<T> theLast = last();
      substitute(node, theLast);
      updateParent(theLast, nullptr);
      theLast.reset();
      --size;
      return true;
      return true;
    }
    if (node->getLeft() != nullptr) {
      nodes.push(node->getLeft());
    }
    if (node->getRight() != nullptr) {
      nodes.push(node->getRight());
    }
  }
  return false;
}
}  // namespace JV
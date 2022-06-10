// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>

template <typemane T>
  struct Node {
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
    Node<T> *prev = nullptr;
    int count = 0;
    T value = "";
  };

template <typemane T>
class BST {
 private:
    Node<T> *root = nullptr;
    int depthValue = 0;
    void printTree(Node<T> *tree, int index) {
      std::cout << index << " " << tree->value << std::endl;
      ++index;
      if (tree->left != nullptr) {
        printTree(tree->left, index);
      }
      if (tree->right != nullptr) {
        printTree(tree->right, index);
      }
    }
    void getDepth(Node<T> *tree, int index) {
      ++index;
      if (tree->left != nullptr) {
        getDepth(tree->left, index);
      }
      if (tree->right != nullptr) {
        getDepth(tree->right, index);
      }
      index > depthValue? depthValue = index: depthValue;
    }
    void deleteNode(Node<T> *node) {
      if (node->left != nullptr) {
        deleteNode(node->left);
      }
      if (node->right != nullptr) {
        deleteNode(node->right);
      }
      delete node;
    }

 public:
    BST() {
      root = nullptr;
      depthValue = 0;
    }
    ~BST() {
      deleteNode(root);
    }
    void add(T element) {
      Node<T> *current = root;
      Node<T> *prev = nullptr;
      int pos = 0;
      while (true) {
        if (current == nullptr) {
          current = new Node<T>;
          current->left = nullptr;
          current->right = nullptr;
          current->value = element;
          current->count = 1;
          if (prev != nullptr) {
            current->prev = prev;
            pos == 1? prev->right = current: prev->left = current;
            pos = 0;
            prev = nullptr;
          }
          if (root == nullptr) {
            root = current;
          }
          break;
        }
        if (current->value < element) {
          prev = current;
          pos = 1;
          current = current->right;
        } else if (current->value == element) {
          current->count++;
          break;
        } else {
           prev = current;
           pos = -1;
           current = current->left;
        }
      }
    }
    int search(T element) {
      Node<T> *current = root;
      while (true) {
        if (current == nullptr) {
          throw std::string("Element not found!");
        } else if (current->value < element) {
          current = current->right;
        } else if (current->value == element) {
          return current->count;
        } else {
          current = current->left;
        }
      }
    }
    void print() {
      Node<T> *current = root;
      printTree(current, 0);
    }
    int depth() {
      Node<T> *current = root;
      getDepth(current, 0);
      return depthValue - 1;
    }
};

  
#endif  // INCLUDE_BST_H_

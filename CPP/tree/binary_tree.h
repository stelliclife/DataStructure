#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <vector>

template <typename T>
class Node
{
private:
  T value;
  Node<T>* left;
  Node<T>* right;
public:
  Node(T input_value);
  void set_value(T input_value);
  void set_left(Node<T>* node);
  void set_right(Node<T>* node);
  T get_value();
  Node<T>* get_left();
  Node<T>* get_right();
  ~Node();
};

template <typename T>
class BinaryTreeList
{
private:
  Node<T>* root;
  vector<T> traversal;
public:
  BinaryTreeList();
  void RemoveAll();
  void RecursivePreOrderTraversal(Node<T>* node);
  void RecursivePostOrderTraversal(Node<T>* node);
  void RecursiveInOrderTraversal(Node<T>* node);
  void StackPreOrderTraversal(Node<T>* node);
  void LevelOrderTraversal(Node<T>* node);
  ~BinaryTreeList();
protected:
  void RemoveSubtree(Node<T>* node);
};

#endif
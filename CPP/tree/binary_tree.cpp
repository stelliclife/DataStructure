#include <iostream>
#include <vector>
#include <stack>
#include "binary_tree.h"

template <typename T>
Node<T>::Node(T input_value)
  : value(input_value)
{
  left = nullptr;
  right = nullptr;
}

template <typename T>
void Node<T>::set_value(T input_value)
{
  value = input_value;
}

template <typename T>
void Node<T>::set_left(Node<T>* node)
{
  left = node;
}

template <typename T>
void Node<T>::set_right(Node<T>* node)
{
  right = node;
}

template <typename T>
T Node<T>::get_value()
{
  return value;
}

template <typename T>
Node<T>* Node<T>::get_left()
{
  return left;
}

template <typename T>
Node<T>* Node<T>::get_right()
{
  return right;
}

template <typename T>
Node<T>::~Node()
{
  delete left;
  delete right;
}

template <typename T>
BinaryTreeList<T>::BinaryTreeList()
{
  root = nullptr;
}

template <typename T>
void BinaryTreeList<T>::RemoveAll()
{
  this->RemoveSubtree(root);
  root = nullptr;
}

template <typename T>
void BinaryTreeList<T>::RecursivePreOrderTraversal(Node<T>* node)
{
  traversal.push_back(node);
  if (node->get_left() != nullptr)
    PreOrderTraversal(node->get_left());
  if (node->get_right() != nullptr)
    PrOrderTraversal(node->get_right());
}

template <typename T>
void BinaryTreeList<T>::RecursiveInOrderTraversal(Node<T>* node)
{
  if (node->get_left() != nullptr)
    InOrderTraversal(node->get_left());
  traversal.push_back(node);
  if (node->get_right() != nullptr)
    InOrderTraversal(node->get_right());
}

template <typename T>
void BinaryTreeList<T>::RecursivePostOrderTraversal(Node<T>* node)
{
  if (node->get_left() != nullptr)
    PostOrderTraversal(node->get_left());
  if (node->get_right() != nullptr)
    PostOrderTraversal(node->get_right());
  traversal.push_back(node);
}

template <typename T>
void BinaryTreeList<T>::StackPreOrderTraversal(Node<T>* node)
{
  stack<Node<T>> temp;

  if ((node == temp.top()) && !temp.empty())
    temp.pop();
  if (node->get_right())
      temp.push(node->get_right());
  if (node->get_left())
      temp.push(node->get_left());
  temp.push(node);
  Node<T> top_node = temp.top();
  traversal.push_back(top_node);
}

template <typename T>
void BinaryTreeList<T>::LevelOrderTraversal(Node<T>* node)
{
  Node<T> target = find(traversal.begin(), traversal.end(), node);
  if (target != traversal.end())
    traversal.push_back(node);
  if (node->get_left())
    traversal.push_back(node->get_left());
  if (node->get_right())
    traversal.push_back(node->get_right());
}

template <typename T>
BinaryTreeList<T>::~BinaryTreeList()
{
  RemoveAll();
  delete root;
  traversal.clear();
}

template <typename T>
void BinaryTreeList<T>::RemoveSubtree(Node<T>* node)
{
  if (node->get_left() != nullptr)
    RemoveSubtree(node->get_left());
  if (node->get_right() != nullptr)
    RemoveSubtree(node->get_right());
  delete node;
}
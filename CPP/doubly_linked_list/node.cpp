#include <iostream>
#include "node.h"

template <typename T>
Node<T>::Node(const T input_value)
  : value(input_value)
{
  Node<T>* previous = nullptr;
  Node<T>* next = nullptr;
}

template <typename T>
void Node<T>::set_value(const T input_value) 
{
  value = input_value;
}

template <typename T>
void Node<T>::set_previous(Node<T>* node)
{
  previous = node;
}

template <typename T>
void Node<T>::set_next(Node<T>* node)
{
  next = node;
}

template <typename T>
T const Node<T>::get_value() const
{
  return value;
}

template <typename T>
Node<T>* const Node<T>::get_previous() const
{
  return previous;
}

template <typename T>
Node<T>* const Node<T>::get_next() const
{
  return next;
}

template <typename T>
Node<T>::~Node() 
{
  delete previous;
  delete next;
}
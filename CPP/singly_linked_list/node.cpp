#include <iostream>
#include "node.h"

template <typename T>
Node<T>::Node(const T input_value)
  : value(input_value)
{
  next = nullptr;
}

template <typename T>
void Node<T>::set_value(const T input_value)
{
  value = input_value;
}

template <typename T>
void Node<T>::set_next(Node<T>* target)
{
  next = target;
}

template <typename T>
T const Node<T>::get_value() const
{
  return value;
}

template <typename T>
Node<T>* const Node<T>::get_next() const
{
  return next;
}

template <typename T>
Node<T>::~Node()
{
  delete next;
}
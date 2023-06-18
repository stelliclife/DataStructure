#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template <typename T>
class Node
{
private:
  T value;
  Node<T>* next;
public:
  Node(const T input_value);
  void set_value(const T input_value);
  void set_next(Node<T>* node);
  T const get_value() const;
  Node<T>* get_next();
  ~Node();
};

template <typename T>
class StackArray
{
private: 
  int top;
  int size;
  T* space;
public:
  StackArray();
  void Push(T value);
  T Pop();
  T Peek();
  void Resize();
  bool IsFull();
  bool IsEmpty();
  void ShowArray();
  ~StackArray();
};

template <typename T>
class StackList
{
private: 
  Node<T>* top;
  int size;
public: 
  StackList();
  void Push(T input_value);
  void Pop();
  Node<T>* Peek();
  bool IsEmpty();
  void ShowList();
  ~StackList();
};

#endif
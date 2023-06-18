#include <iostream>
#include "stack.h"

using std::cout;
using std::endl;

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
Node<T>* Node<T>::get_next()
{
  return next;
}

template <typename T>
Node<T>::~Node()
{
  delete next;
}

template <typename T>
StackArray<T>::StackArray()
  : top(-1), size(1)
{
  space = new T[1];
}

template <typename T>
void StackArray<T>::Push(const T value)
{
  if (IsFull())
    Resize();
  space[++top] = value;
}

template <typename T>
T StackArray<T>::Pop()
{
  T current_value = NULL;
  if (!IsEmpty())
  {
    --top;
    space[top] = NULL;
    current_value = space[top];
  }

  return current_value;
}

template <typename T>
T StackArray<T>::Peek()
{
  return space[top];
}

template <typename T>
void StackArray<T>::Resize()
{
  int temp_size = size * 2;
  T* temp_array = new T[temp_size];
  for (int i = 0; i < size; ++i)
    temp_array[i] = space[i];
  space = temp_array;
  size = temp_size;
}

template <typename T>
bool StackArray<T>::IsFull()
{
  if (top >= 0 && top == size - 1)
    return true;
  return false;
}

template <typename T>
bool StackArray<T>::IsEmpty()
{
  if (top == -1)
    return true;
  return false;
}

template <typename T>
void StackArray<T>::ShowArray()
{
  for (int i = 0; i <= top; ++i)
    cout << space[i] << endl;
}

template <typename T>
StackArray<T>::~StackArray()
{
  delete[] space;
}

template <typename T>
StackList<T>::StackList()
  : size(0)
{
  top = nullptr;
}

template <typename T>
void StackList<T>::Push(T input_value)
{
  Node<T>* current_top = top;
  Node<T>* node = new Node<T>(input_value);
  node->set_next(current_top);
  top = node;
  ++size;
}

template <typename T>
void StackList<T>::Pop()
{
  if (!IsEmpty())
  {
    Node<T>* current_top = top;
    Node<T>* next_node = current_top->get_next();
    current_top->set_next(nullptr);
    top = next_node;
    --size;
  }
}

template <typename T>
Node<T>* StackList<T>::Peek()
{
  return top;
}

template <typename T>
bool StackList<T>::IsEmpty()
{
  if (top == nullptr)
    return true;
  return false;
}

template <typename T>
void StackList<T>::ShowList()
{
  Node<T>* current_top = top;
  T* result = new T[size];
  int i = size;
  while (current_top->get_next())
  {
    result[--i] = current_top->get_value();
    current_top = current_top->get_next();
  }
  result[--i] = current_top->get_value();
  for (i = 0; i < size; ++i)
    cout << result[i] << endl;
}

template <typename T>
StackList<T>::~StackList()
{
  delete top;
}

int main()
{
  StackArray<int>* stack_array = new StackArray<int>();
  StackList<int>* stack_list = new StackList<int>();

  stack_array->Push(5);
  stack_array->Push(3);
  stack_array->Push(8);
  stack_array->Push(4);
  stack_array->Pop();
  stack_array->Push(1);
  stack_array->Push(7);
  stack_array->Pop();
  int peek01 = stack_array->Peek();
  cout << "Peek: " << peek01 << endl;
  stack_array->ShowArray();

  stack_list->Push(5);
  stack_list->Push(3);
  stack_list->Push(8);
  stack_list->Push(4);
  stack_list->Pop();
  stack_list->Push(1);
  stack_list->Push(7);
  stack_list->Pop();
  Node<int>* peek02 = stack_list->Peek();
  cout << "Peek: " << peek02->get_value() << endl;
  stack_list->ShowList();

  return 0;
}
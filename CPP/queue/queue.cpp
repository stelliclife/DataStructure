#include <iostream>
#include "queue.h"

using std::cout;
using std::endl;

template <typename T>
Node<T>::Node(const T input_value)
  : value(input_value)
{
  previous = nullptr;
  next = nullptr;
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
Node<T>* Node<T>::get_previous()
{
  return previous;
}

template <typename T>
Node<T>* Node<T>::get_next()
{
  return next;
}

template <typename T>
Node<T>::~Node()
{
  delete previous;
  delete next;
}

template <typename T>
QueueArray<T>::QueueArray()
  : front(-1), rear(-1), size(1)
{
  space = new T[1];
}

template <typename T>
void QueueArray<T>::Enqueue(const T input_value)
{
  if (IsFull())
    Resize();
  if (front == -1 && rear == -1)
  {
    space[++front] = input_value;
    ++rear;
  }
  else
  {
    space[++rear] = input_value;
  }
}

template <typename T>
T QueueArray<T>::Dequeue()
{
  T target = NULL;
  if (!IsEmpty())
  {
    target = space[front];
    space[front] = NULL;
    ++front;
  }
  return target;
}

template <typename T>
T QueueArray<T>::Peek()
{
  return space[front];
}

template <typename T>
void QueueArray<T>::Resize()
{
  int temp_size = size * 2;
  T* temp_array = new T[temp_size];
  for (int i = 0; i < size; ++i)
    temp_array[i] = space[i];
  space = temp_array;
  size = temp_size;
}

template <typename T>
bool QueueArray<T>::IsEmpty()
{
  if (front == rear)
    return true;
  return false;
}

template <typename T>
bool QueueArray<T>::IsFull()
{
  if (rear == size - 1)
    return true;
  return false;
}

template <typename T>
void QueueArray<T>::ShowArray()
{
  for (int i = front; i <= rear; ++i)
    cout << space[i] << endl;
}

template <typename T>
QueueArray<T>::~QueueArray()
{
  delete[] space;
}

template <typename T>
QueueList<T>::QueueList()
  : size(0)
{
  front = nullptr;
  rear = nullptr;
}

template <typename T>
void QueueList<T>::Enqueue(const T input_value)
{
  Node<T>* node = new Node<T>(input_value);
  if (front == nullptr)
  {
    front = node;
    rear = node;
  }
  else
  {
    Node<T>* current_node = front;
    while (current_node->get_next())
      current_node = current_node->get_next();
    current_node->set_next(node);
    node->set_previous(current_node);
    rear = node;
  }  
}

template <typename T>
Node<T>* QueueList<T>::Dequeue()
{
  Node<T>* target = nullptr;
  if (!IsEmpty())
  {
    Node<T>* current_node = front;
    Node<T>* next_node = current_node->get_next();
    target = current_node;
    current_node->set_next(nullptr);
    next_node->set_previous(nullptr);
    delete current_node;
    front = next_node;
  }
  return target;
}

template <typename T>
Node<T>* QueueList<T>::Peek()
{
  return front;
}

template <typename T>
bool QueueList<T>::IsEmpty()
{
  if (front == nullptr && rear == nullptr)
    return true;
  return false;
}

template <typename T>
void QueueList<T>::ShowList()
{
  Node<T>* current_node = front;
  while (current_node->get_next())
  {
    cout << current_node->get_value() << endl;
    current_node = current_node->get_next();
  }
  cout << current_node->get_value() << endl;
}

template <typename T>
QueueList<T>::~QueueList()
{
  delete front;
  delete rear;
}

int main()
{
  QueueArray<int>* queue_array = new QueueArray<int>();
  QueueList<int>* queue_list = new QueueList<int>();

  queue_array->Enqueue(5);
  queue_array->Enqueue(3);
  queue_array->Enqueue(8);
  queue_array->Enqueue(4);
  queue_array->Dequeue();
  queue_array->Enqueue(1);
  queue_array->Enqueue(7);
  queue_array->Dequeue();
  int peek01 = queue_array->Peek();
  cout << "Peek: " << peek01 << endl;
  queue_array->ShowArray();

  queue_list->Enqueue(5);
  queue_list->Enqueue(3);
  queue_list->Enqueue(8);
  queue_list->Enqueue(4);
  queue_list->Dequeue();
  queue_list->Enqueue(1);
  queue_list->Enqueue(7);
  queue_list->Dequeue();
  Node<int>* peek02 = queue_list->Peek();
  cout << "Peek: " << peek02->get_value() << endl;
  queue_list->ShowList();

  return 0;
}
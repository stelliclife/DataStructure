#include <iostream>
#include "circular_queue.h"

using std::cout;
using std::endl;

template <typename T>
Node<T>::Node(T input_value)
  : value(input_value)
{
  next = nullptr;
}

template <typename T>
void Node<T>::set_value(T input_value)
{
  value = input_value;
}

template <typename T>
void Node<T>::set_next(Node<T>* node)
{
  next = node;
}

template <typename T>
T Node<T>::get_value()
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
CircularQueueArray<T>::CircularQueueArray()
  : front(-1), rear(-1), size(1)
{
  space = new T[1];
}

template <typename T>
void CircularQueueArray<T>::Enqueue(T input_value)
{
  if (IsEmpty()) 
  {
    ++front;
  }
  else if (IsFull())
  {
    Resize();
  }
  rear = (rear + 1) % size;
  space[rear] = input_value;
}

template <typename T>
T CircularQueueArray<T>::Dequeue()
{
  if (IsEmpty())
    return NULL;
  int target = space[front];
  space[front] = NULL;
  if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    front = (front + 1) % size;
  }
  return target;
}

template <typename T>
T CircularQueueArray<T>::Peek()
{
  if (IsEmpty())
    return NULL;
  return space[front];
}

template <typename T>
bool CircularQueueArray<T>::IsEmpty()
{
  return (front == -1 && rear == -1);
}

template <typename T>
bool CircularQueueArray<T>::IsFull()
{
  return (((rear + 1) % size) == front);
}

template <typename T>
void CircularQueueArray<T>::Resize()
{
  int temp_size = size * 2;
  T* temp_array = new T[temp_size];
  for (int i = 0; i < temp_size; ++i)
  {
    temp_array[i] = NULL;
  }

  for (int i = 0; i < size; ++i)
  {
    if (i <= rear)
      temp_array[i] = space[i];
    else if (i > rear && (i + (temp_size / 2)) < temp_size)
      temp_array[i + (temp_size / 2)] = space[i];
  }
  if(front > rear)
    front = (temp_size / 2) + rear + 1;
  space = temp_array;
  size = temp_size;
}

template <typename T>
void CircularQueueArray<T>::ShowArray()
{
  if (!IsEmpty())
  {
    for (int i = 0; i < size; ++i)
    {
      if (space[i] == NULL)
        cout << "NULL" << endl;
      else
        cout << space[i] << endl;
    }
  }
}

template <typename T>
CircularQueueArray<T>::~CircularQueueArray()
{
  delete[] space;
}

template <typename T>
CircularQueueList<T>::CircularQueueList()
{
  front = nullptr;
  rear = nullptr;
}

template <typename T>
void CircularQueueList<T>::Enqueue(T input_value)
{
  Node<T>* node = new Node<T>(input_value);
  if (IsEmpty())
  {
    front = node;
    rear = node;
  }
  else
  {
    Node<T>* current_node = rear;
    current_node->set_next(node);
    node->set_next(front);
    rear = node;
  }
}

template <typename T>
Node<T>* CircularQueueList<T>::Dequeue()
{
  Node<T>* current_node = front;
  Node<T>* next_node = current_node->get_next();
  Node<T>* target = nullptr;

  if (!IsEmpty())
  {
    rear->set_next(next_node);
    current_node->set_next(nullptr);
    target = current_node;
    delete target;
    front = next_node;
  }

  return current_node;
}

template <typename T>
Node<T>* CircularQueueList<T>::Peek()
{
  return front;
}

template <typename T>
bool CircularQueueList<T>::IsEmpty()
{
  return (front == nullptr && rear == nullptr);
}

template <typename T>
void CircularQueueList<T>::ShowList()
{
  Node<T>* current_node = front;
  while (current_node != rear)
  {
    cout << current_node->get_value() << endl;
    current_node = current_node->get_next();
  }
  cout << current_node->get_value() << endl;
}

template <typename T>
CircularQueueList<T>::~CircularQueueList()
{
  delete front;
  delete rear;
}

int main()
{
  CircularQueueArray<int>* queue_array = new CircularQueueArray<int>();
  CircularQueueList<int>* queue_list = new CircularQueueList<int>();

  queue_array->Enqueue(5);
  queue_array->Enqueue(3);
  queue_array->Enqueue(8);
  queue_array->Enqueue(4);
  queue_array->Dequeue();
  queue_array->Enqueue(1);
  queue_array->Enqueue(7);
  queue_array->Dequeue();
  queue_array->ShowArray();
  int peek01 = queue_array->Peek();
  cout << "Peek: " << peek01 << endl;

  queue_list->Enqueue(5);
  queue_list->Enqueue(3);
  queue_list->Enqueue(8);
  queue_list->Enqueue(4);
  queue_list->Dequeue();
  queue_list->Enqueue(1);
  queue_list->Enqueue(7);
  queue_list->Dequeue();
  queue_list->ShowList();
  Node<int>* peek02 = queue_list->Peek();
  cout << "Peek: " << peek02->get_value() << endl;

  return 0;
}
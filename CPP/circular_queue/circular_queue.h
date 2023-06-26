#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

template <typename T>
class Node
{
private:
  T value;
  Node<T>* next;
public:
  Node(T input_value);
  void set_value(T input_value);
  void set_next(Node<T>* node);
  T get_value();
  Node<T>* get_next();
  ~Node();
};

template <typename T>
class CircularQueueArray
{
private:
  int front;
  int rear;
  int size;
  T* space;
public:
  CircularQueueArray();
  void Enqueue(T input_value);
  T Dequeue();
  T Peek();
  bool IsEmpty();
  bool IsFull();
  void Resize();
  void ShowArray();
  ~CircularQueueArray();
};

template <typename T>
class CircularQueueList
{
private:
  Node<T>* front;
  Node<T>* rear;
public:
  CircularQueueList();
  void Enqueue(T input_value);
  Node<T>* Dequeue();
  Node<T>* Peek();
  bool IsEmpty();
  void ShowList();
  ~CircularQueueList();
};

#endif
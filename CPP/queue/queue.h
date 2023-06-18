#ifndef QUEUE_H_
#define QUEUE_H_

template <typename T>
class Node
{
private:
  T value;
  Node<T>* previous;
  Node<T>* next;
public:
  Node(const T input_value);
  void set_value(const T input_value);
  void set_previous(Node<T>* node);
  void set_next(Node<T>* node);
  T const get_value() const;
  Node<T>* get_previous();
  Node<T>* get_next();
  ~Node();
};

template <typename T>
class QueueArray
{
private:
  int front;
  int rear;
  int size;
  T* space;
public:
  QueueArray();
  void Enqueue(const T input_value);
  T Dequeue();
  T Peek();
  void Resize();
  bool IsEmpty();
  bool IsFull();
  void ShowArray();
  ~QueueArray();
};

template <typename T>
class QueueList
{
private:
  Node<T>* front;
  Node<T>* rear;
  int size;
public:
  QueueList();
  void Enqueue(const T input_value);
  Node<T>* Dequeue();
  Node<T>* Peek();
  bool IsEmpty();
  void ShowList();
  ~QueueList();
};

#endif
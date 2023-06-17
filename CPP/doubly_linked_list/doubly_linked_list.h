#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_

#include "node.h"
#include "node.cpp"

template <typename T>
class DoublyLinkedList
{
private:
  Node<T>* head;
  Node<T>* tail;
public:
  DoublyLinkedList();
  void AddNodeToEnd(const T value);
  void AddNodeToStart(const T value);
  void InsertNodeAfter(const T target_value, const T value);
  void InsertNodeBefore(const T target_value, const T value);
  Node<T>* DeleteNodeAtEnd();
  Node<T>* DeleteNodeAtStart();
  Node<T>* DeleteNodeAfter(const T value);
  Node<T>* DeleteNodeBefore(const T value);
  void ShowList();
  ~DoublyLinkedList();
};

#endif
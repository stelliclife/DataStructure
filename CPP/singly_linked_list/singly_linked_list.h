#ifndef SINGLY_LINKED_LIST_
#define SINGLY_LINKED_LIST_

#include "node.h"
#include "node.cpp"

template <typename T>
class SinglyLinkedList
{
private: 
  Node<T>* head;
public:
  SinglyLinkedList();
  void AddNodeToEnd(const T value);
  void AddNodeToStart(const T value);
  void InsertNode(const T target_value , const T value);
  Node<T>* DeleteNodeAtEnd();
  Node<T>* DeleteNodeAtStart();
  Node<T>* DeleteNodeAfter(const T value);
  void ShowList();
  ~SinglyLinkedList();
};

#endif
#include <iostream>
#include "singly_linked_list.h"

using std::cout;
using std::endl;

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
  head = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::AddNodeToEnd(const T value)
{
  Node<T>* node = new Node<T>(value);

  if (head == nullptr)
  {
    head = node;
  }
  else
  {
    Node<T>* current_node = head;
    while (current_node->get_next())
    {
      current_node = current_node->get_next();
    }
    current_node->set_next(node);
  }
}

template <typename T>
void SinglyLinkedList<T>::AddNodeToStart(const T value)
{
  Node<T>* node = new Node<T>(value);
  
  if (head == nullptr)
  {
    head = node;
  }
  else
  {
    Node<T>* current_node = head;
    node->set_next(current_node);
    head = node;
  }
}

template <typename T>
void SinglyLinkedList<T>::InsertNode(const T target_value, const T value)
{
    Node<T> *current_node = head;
    Node<T> *next_node = current_node->get_next();

    while (next_node->get_next())
    {
        if (current_node->get_value() == target_value)
        {
          Node<T>* node = new Node<T>(value);
          current_node->set_next(node);
          node->set_next(next_node);
          break;
        }
        current_node = next_node;
        next_node = next_node->get_next();
    }
}

template <typename T>
Node<T>* SinglyLinkedList<T>::DeleteNodeAtEnd()
{
  Node<T> *current_node = head;
  Node<T> *next_node = current_node->get_next();

  while (next_node->get_next())
  {
    current_node = next_node;
    next_node = next_node->get_next();
  }
  current_node->set_next(nullptr);
  Node<T> *target_node = next_node;
  delete target_node;

  return next_node;
}

template <typename T>
Node<T>* SinglyLinkedList<T>::DeleteNodeAtStart()
{
  Node<T> *current_node = head;
  Node<T> *next_node = current_node->get_next();

  head = current_node->get_next();
  current_node->set_next(nullptr);
  Node<T> *target_node = current_node;
  delete target_node;

  return current_node;
}

template <typename T>
Node<T>* SinglyLinkedList<T>::DeleteNodeAfter(const T value)
{
  Node<T> *previous_node = head;
  Node<T> *current_node = previous_node->get_next();
  Node<T> *next_node = current_node->get_next();
  Node<T> *target_node = nullptr;

  while (next_node->get_next())
  {
    if (current_node->get_value() == value)
    {
      current_node->set_next(nullptr);
      target_node = current_node;
      previous_node->set_next(next_node);
      delete current_node;
      break;
    }
    previous_node = current_node;
    current_node = next_node;
    next_node = next_node->get_next();
  }

  return target_node;
}

template <typename T>
void SinglyLinkedList<T>::ShowList()
{
  Node<T> *current_node = head;
  while(current_node->get_next())
  {
    cout << current_node->get_value() << endl;
    current_node = current_node->get_next();
  }
  cout << current_node->get_value() << endl;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
  delete head;
}

int main()
{
  SinglyLinkedList<int> *linked_list = new SinglyLinkedList<int>();
  linked_list->AddNodeToEnd(5);
  linked_list->AddNodeToEnd(1);
  linked_list->AddNodeToStart(8);
  linked_list->InsertNode(5, 3);
  linked_list->AddNodeToEnd(2);
  linked_list->AddNodeToStart(4);
  linked_list->InsertNode(1, 6);
  linked_list->DeleteNodeAtEnd();
  linked_list->DeleteNodeAtStart();
  linked_list->DeleteNodeAfter(3);
  linked_list->ShowList();

  delete linked_list;

  return 0;
}
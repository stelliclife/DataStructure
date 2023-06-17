#include <iostream>
#include "doubly_linked_list.h"

using std::cout;
using std::endl;

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  head = nullptr;
  tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::AddNodeToEnd(const T value)
{
  Node<T>* node = new Node<T>(value);

  if (head == nullptr && tail == nullptr)
  {
	head = node;
	tail = node;
  }
  else
  {
    Node<T>* current_node = tail;
	current_node->set_next(node);
	node->set_previous(current_node);
	tail = current_node->get_next();
  }
}

template <typename T>
void DoublyLinkedList<T>::AddNodeToStart(const T value)
{
  Node<T>* node = new Node<T>(value);
  
  if (head == nullptr && tail == nullptr)
  {
	head = node;
	tail = node;
  }
  else
  {
	Node<T>* current_node = head;
	current_node->set_previous(node);
	node->set_next(current_node);
	head = current_node->get_previous();
  }
}

template <typename T>
void DoublyLinkedList<T>::InsertNodeAfter(const T target_value, const T value)
{
  Node<T>* current_node = head;
  Node<T>* next_node = current_node->get_next();

  while (next_node->get_next())
  {
	if (current_node->get_value() == target_value)
	{
	  Node<T>* node = new Node<T>(value);
	  current_node->set_next(node);
	  node->set_previous(current_node);
	  node->set_next(next_node);
	  next_node->set_previous(node);
	  break;
	}
	current_node = next_node;
	next_node = next_node->get_next();
  }
}

template <typename T>
void DoublyLinkedList<T>::InsertNodeBefore(const T target_value, const T value)
{
  Node<T>* current_node = tail;
  Node<T>* previous_node = current_node->get_previous();

  while (previous_node->get_previous())
  {
	if (current_node->get_value() == target_value)
	{
	  Node<T>* node = new Node<T>(value);
	  current_node->set_previous(node);
	  node->set_next(current_node);
	  node->set_previous(previous_node);
	  previous_node->set_next(node);
	}
	current_node = previous_node;
	previous_node = previous_node->get_previous();
  }
}

template <typename T>
Node<T>* DoublyLinkedList<T>::DeleteNodeAtEnd()
{
  Node<T>* current_node = tail;
  Node<T>* previous_node = current_node->get_previous();
  current_node->set_previous(nullptr);
  previous_node->set_next(nullptr);
  Node<T>* target_node = current_node;
  delete current_node;
  tail = previous_node;

  return target_node;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::DeleteNodeAtStart()
{
  Node<T>* current_node = head;
  Node<T>* next_node = current_node->get_next();
  current_node->set_next(nullptr);
  next_node->set_previous(nullptr);
  Node<T>* target_node = current_node;
  delete current_node;
  head = next_node;

  return target_node;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::DeleteNodeAfter(const T value)
{
  Node<T>* previous_node = head;
  Node<T>* current_node = previous_node->get_next();
  Node<T>* next_node = current_node->get_next();
  Node<T>* target_node = nullptr;

  while (next_node->get_next())
  {
	if (current_node->get_value() == value)
	{
      current_node->set_next(nullptr);
	  previous_node->set_next(next_node);
	  current_node->set_previous(nullptr);
	  next_node->set_previous(previous_node);
	  target_node = current_node;
      break;
	}
	previous_node = current_node;
	current_node = next_node;
	next_node = next_node->get_next();
  }

  return target_node;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::DeleteNodeBefore(const T value)
{
  Node<T>* next_node = tail;
  Node<T>* current_node = next_node->get_previous();
  Node<T>* previous_node = current_node->get_previous();
  Node<T>* target_node = nullptr;

  while (previous_node->get_previous())
  {
    if (current_node->get_value() == value)
	{
      current_node->set_next(nullptr);
	  previous_node->set_next(next_node);
	  current_node->set_previous(nullptr);
	  next_node->set_previous(previous_node);
	  target_node = current_node;
	  break;
	}
	next_node = current_node;
	current_node = next_node;
	previous_node = previous_node->get_previous();
  }

  return target_node;
}

template <typename T>
void DoublyLinkedList<T>::ShowList()
{
  Node<T>* current_node = head;

  while (current_node->get_next())
  {
	cout << current_node->get_value() << endl;
	current_node = current_node->get_next();
  }
  cout << current_node->get_value() << endl;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  delete head;
  delete tail;
}

int main()
{
  DoublyLinkedList<int> *linked_list = new DoublyLinkedList<int>();
  linked_list->AddNodeToEnd(5);
  linked_list->AddNodeToEnd(1);
  linked_list->AddNodeToStart(8);
  linked_list->InsertNodeAfter(5, 3);
  linked_list->AddNodeToEnd(2);
  linked_list->AddNodeToStart(4);
  linked_list->InsertNodeBefore(1, 6);
  linked_list->DeleteNodeAtEnd();
  linked_list->DeleteNodeAtStart();
  linked_list->DeleteNodeAfter(3);
  linked_list->ShowList();

  delete linked_list;

  return 0;
}
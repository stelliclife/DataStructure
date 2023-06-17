#ifndef NODE_H_
#define NODE_H_

template <typename T>
class Node
{
private:
	T value;
	Node<T>* next;
public:
	Node(const T input_value);
	void set_value(const T input_value);
	void set_next(Node<T> *target);
	T const get_value() const;
	Node<T>* const get_next() const;
	~Node();
};

#endif
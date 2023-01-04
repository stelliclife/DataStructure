class Node:
    def __init__(self, data):
        self._data = data
        self._next = None

    @property
    def data(self):
        return self._data

    @property
    def next(self):
        return self._next

    @next.setter
    def next(self, node):
        self._next = node


class LinkedList:
    def __init__(self):
        self._head = None

    def add_node_to_end(self, value):
        node = Node(value)

        if not self._head:
            self._head = node
        else:
            current_node = self._head
            while current_node.next:
                current_node = current_node.next
            current_node.next = node

    def add_node_to_start(self, value):
        node = Node(value)
        node.next = self._head
        self._head = node

    def insert_node(self, target, value):
        node = Node(value)
        current_node = self._head

        while current_node.data != target:
            current_node = current_node.next
        node.next = current_node.next
        current_node.next = node

    def delete_node_at_end(self):
        if not (self._head and self._head.next):
            return self._head

        current_node = self._head
        next_node = current_node.next

        while next_node.next:
            current_node = next_node
            next_node = next_node.next
        current_node.next = None

        return next_node

    def delete_node_at_start(self):
        self._head = self._head.next

        return self._head

    def delete_node_after(self, value):
        current_node = self._head

        while current_node.data != value or current_node.next is None:
            current_node = current_node.next
        target_node = current_node.next
        current_node.next = target_node.next

        return target_node
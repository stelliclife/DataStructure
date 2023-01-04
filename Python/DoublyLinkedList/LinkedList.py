class Node:
    def __init__(self, data):
        self._data = data
        self._previous = None
        self._next = None

    @property
    def data(self):
        return self._data

    @property
    def previous(self):
        return self._previous

    @previous.setter
    def previous(self, node):
        self._previous = node

    @property
    def next(self):
        return self._next

    @next.setter
    def next(self, node):
        self._next = node


class LinkedList:
    def __init__(self):
        self._head = None
        self._tail = None

    def add_node_to_end(self, value):
        node = Node(value)

        if not self._head and not self._tail:
            self._head = node
            self._tail = node
        else:
            current_node = self._head

            while current_node.next:
                current_node = current_node.next
            current_node.next = node
            node.previous = current_node
            self._tail = node

    def add_node_to_start(self, value):
        node = Node(value)

        if not self._head and not self._tail:
            self._head = node
            self._tail = node
        else:
            current_node = self._head
            node.next = current_node
            current_node.previous = node
            self._head = node


    def insert_node_after(self, target, value):
        current_node = self._head
        next_node = current_node.next

        while current_node.data != target:
            current_node = next_node
            next_node = next_node.next
        if current_node.next:
            node = Node(value)
            node.next = next_node
            node.previous = current_node
            current_node.next = node
            next_node.previous = node

    def insert_node_before(self, target, value):
        current_node = self._tail
        previous_node = current_node.previous

        while current_node.data != target:
            current_node = previous_node
            previous_node = previous_node.previous
        if current_node.previous:
            node = Node(value)
            current_node.previous = node
            previous_node.next = node
            node.next = current_node
            node.previous = previous_node

    def delete_node_at_end(self):
        if not (self._tail and self._tail.previous):
            return self._tail

        target = self._tail
        self._tail = self._tail.previous
        self._tail.next = None

        return target

    def delete_node_at_start(self):
        if not (self._head and self._head.next):
            return self._head

        target = self._head
        self._head = self._head.next
        self._head.previous = None

        return target

    def delete_node_after(self, value):
        current_node = self._head
        next_node = current_node.next

        while current_node.data != value:
            current_node = next_node
            next_node = next_node.next
        target = next_node
        next_node = next_node.next
        next_node.previous = current_node
        current_node.next = next_node

        return target

    def delete_node_before(self, value):
        current_node = self._tail
        previous_node = current_node.previous

        while current_node.data != value:
            current_node = previous_node
            previous_node = previous_node.previous
        target = previous_node
        previous_node = previous_node.previous
        previous_node.next = current_node
        current_node.previous = previous_node

        return target
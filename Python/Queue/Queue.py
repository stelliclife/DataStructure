class QueueArray:
    def __init__(self, array_size):
        self._front = -1
        self._rear = -1
        self._array = [0] * array_size

    def enqueue(self, value):
        if self.is_empty():
            self._front += 1
        if not self.is_full():
            self._rear += 1
            self._array[self._rear] = value

    def dequeue(self):
        if self.is_empty():
            return None
        target = self._array[self._front]
        self._array[self._front] = 0
        if self._front == self._rear:
            self._front = self._rear = -1
        else:
            self._front += 1
        return target

    def peek(self):
        if self.is_empty():
            return None
        return self._array[self._front]

    def is_empty(self):
        if self._front == -1:
            return True
        return False

    def is_full(self):
        if self._rear == len(self._array):
            return True
        return False


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


class QueueLinkedList:
    def __init__(self, list_size):
        self._front = None
        self._rear = None
        self._list_size = list_size

    def enqueue(self, value):
        node = Node(value)

        if self.is_empty():
            self._front = self._rear = node
        elif not (self.is_empty() or self.is_full()):
            self._rear.next = node
            self._rear = self._rear.next
            self._rear.previous = node.previous

    def dequeue(self):
        if self.is_empty():
            return None

        target = self._front
        self._front = self._front.next

        return target

    def peek(self):
        if self.is_empty():
            return None
        return self._front

    def is_empty(self):
        if not self._front:
            return True
        return False

    def is_full(self):
        count = 0
        current_node = self._rear
        while current_node:
            count += 1
            current_node = current_node.previous

        if count == self._list_size:
            return True
        return False
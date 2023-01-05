class StackArray:
    def __init__(self):
        self._size = 0
        self._array = [0]
        self._top = -1

    def push(self, value):
        if self.is_full():
            self.resize()
        self._top += 1
        self._array[self._top] = value
        self._size += 1

    def pop(self):
        if not self.is_empty():
            target = self.peek()
            self._array.pop(self._top)
            self._top -= 1
            self._size -= 1
            return target
        return None

    def peek(self):
        if not self.is_empty():
            return self._array[self._top]
        return None

    def resize(self):
        length = len(self._array)
        temp = [0] * (length * 2)
        for i in range(length):
            temp[i] = self._array[i]
        self._array = temp

    def is_full(self):
        if self._size == len(self._array):
            return True
        return False

    def is_empty(self):
        if self._top < 0:
            return True
        return False


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


class StackLinkedList:
    def __init__(self):
        self._top = None
        self._size = 0

    def push(self, value):
        node = Node(value)

        node.next = self._top
        self._top = node
        self._size += 1

    def pop(self):
        if self.is_empty():
            return None

        target = self._top
        self._top = self._top.next
        target.next = None
        self._size -= 1

        return target

    def peek(self):
        if not self._top:
            return None
        return self._top.data

    def is_empty(self):
        if self._size:
            return False
        return True
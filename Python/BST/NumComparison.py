class Node:
    def __init__(self, data):
        self._data = data
        self._left = None
        self._right = None

    @property
    def data(self):
        return self._data

    @property
    def left(self):
        return self._left

    @left.setter
    def left(self, node):
        self._left = node

    @property
    def right(self):
        return self._right

    @right.setter
    def right(self, node):
        self._right = node

class BinarySearchTree:
    def __init__(self):
        self._root = None

    def find_minimum_number(self, node=None):
        if not node:
            node = self._root
        if not node.left:
            return node
        node = node.left
        return self.find_minimum_number(node)

    def find_maximum_number(self, node=None):
        if not node:
            node = self._root
        if not node.right:
            return node
        node = node.right
        return self.find_maximum_number(node)

    def search(self, node, value):
        if not node and self._root:
            current_node = self._root
        else:
            current_node = node

        if current_node.data == value:
            return current_node
        elif current_node.data > value:
            if current_node.left:
                return self.search(current_node.left, value)
            else:
                return None
        elif current_node.data < value:
            if current_node.right:
                return self.search(current_node.right, value)
            else:
                return None

    def insert(self, value, node):
        if not self._root:
            new_node = Node(value)
            self._root = new_node

        if not node and self._root:
            current_node = self._root
        else:
            current_node = node

        if current_node.data > value:
            if current_node.left:
                self.insert(value, current_node.left)
            else:
                current_node.left = Node(value)
        elif current_node.data < value:
            if current_node.right:
                self.insert(value, current_node.right)
            else:
                current_node.right = Node(value)
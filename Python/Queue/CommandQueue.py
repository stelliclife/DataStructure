class PriorityQueue:
    """
    Create Priority Queue to run a sequence of commands by using Heap
    """
    def __init__(self):
        self._array = []
        self._result = []
        self._size = 0

    @property
    def result(self):
        """
        Get a sorted list

        Return: list
        """
        return self._result

    def enqueue(self, process):
        """
        Enqueue a new command into a queue

        Argument:
            data: dict
        """
        self._array.append(process)
        self._result.append(-1)
        self._size += 1
        index = self._size-1

        while index >= 0:
            if (index-1) % 2 == 0:
                parent = (index-1) // 2
            else:
                parent = (index-2) // 2
            if parent < 0:
                break
            if self._array[parent]["priority"] <= self._array[index]["priority"]:
                self._array[parent], self._array[index] = self._array[index], self._array[parent]
                index = parent
            else:
                break

    def dequeue(self, command):
        """
        Dequeue a specific command from a queue

        Argument:
            command:
        Return: None/dict
        """
        if self.is_empty():
            return None

        target = None
        for process in self._array:
            if process["command"] == command:
                target = process
                break

        if not target:
            return None

        index = self._array.index(target)
        self._array[index], self._array[self._size-1] = self._array[self._size-1], self._array[index]
        self._array.pop(self._size-1)
        self._result.pop(-1)
        self._size -= 1

        while index >= 0:
            if (index-1) % 2 == 0:
                parent = (index-1) // 2
            else:
                parent = (index-2) // 2
            if parent < 0 or index > self._size-1:
                break
            if self._array[parent]["priority"] <= self._array[index]["priority"]:
                self._array[parent], self._array[index] = self._array[index], self._array[parent]
                index = parent
            else:
                break
        return target

    def poll(self):
        """
        Dequeue a process having the highest priority

        Return: None/dict
        """
        if self.is_empty():
            return None

        target = None
        self.heapify(self._size)
        length = len(self._result)
        for i in range(length):
            if self._result[i] == -1:
                target = self._result[i] = self._array[self._size-1]
                break
        self._array.pop(self._size-1)
        self._size -= 1
        return target

    def peek(self):
        """
        Return a peek

        Return: None/dict
        """
        if self.is_empty():
            return None
        return self._array[0]

    def is_empty(self):
        """
        Check if a queue is empty

        Return: bool
        """
        if self._size == 0:
            return True
        return False

    def heapify(self, size):
        """
        Sort a queue by priority

        Argument:
            size: int
        """
        n = size // 2 - 1
        l = n * 2 + 1
        r = n * 2 + 2

        while n >= 0:
            if l < size and self._array[n]["priority"] <= self._array[l]["priority"]:
                self._array[n], self._array[l] = self._array[l], self._array[n]
            if r < size and self._array[n]["priority"] <= self._array[r]["priority"]:
                self._array[n], self._array[r] = self._array[r], self._array[n]
            if n == 0:
                self._array[n], self._array[size-1] = self._array[size-1], self._array[n]
            n -= 1
            l = n * 2 + 1
            r = n * 2 + 2
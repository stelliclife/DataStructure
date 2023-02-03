class PriorityQueue:
    def __init__(self, array):
        self._array = array
        self._size = len(array)
        self._result = [-1]*self._size

    @property
    def result(self):
        return self._result

    def add(self, value):
        if self.is_full():
            return False

        self._array.append(value)
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
            if self._array[parent] <= self._array[index]:
                self._array[parent], self._array[index] = self._array[index], self._array[parent]
                index = parent
            else:
                break
        return True

    def delete(self, value):
        if self.is_empty():
            return None

        if value not in self._array:
            return None

        index = self._array.index(value)

        self._array[index], self._array[self._size-1] = self._array[self._size-1], self._array[index]
        self._array.pop(self._size-1)
        self._size -= 1

        while index >= 0:
            if (index-1) % 2 == 0:
                parent = (index-1) // 2
            else:
                parent = (index-2) // 2
            if parent < 0 or index > self._size-1:
                break
            if self._array[parent] <= self._array[index]:
                self._array[parent], self._array[index] = self._array[index], self._array[parent]
                index = parent
            else:
                break
        return value

    def poll(self):
        if self.is_empty():
            return None

        target = 0
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
        if self.is_empty():
            return None
        return self._array[0]

    def is_empty(self):
        if self._size == 0:
            return True
        return False

    def is_full(self):
        if self._size == len(self._result):
            return True
        return False

    def heapify(self, size):
        n = size // 2 - 1
        l = n * 2 + 1
        r = n * 2 + 2

        while n >= 0:
            if l < size and self._array[n] <= self._array[l]:
                self._array[n], self._array[l] = self._array[l], self._array[n]
            if r < size and self._array[n] <= self._array[r]:
                self._array[n], self._array[r] = self._array[r], self._array[n]
            if n == 0:
                self._array[n], self._array[size-1] = self._array[size-1], self._array[n]
            n -= 1
            l = n * 2 + 1
            r = n * 2 + 2
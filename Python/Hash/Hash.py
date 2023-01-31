class Entry:
    def __init__(self, key, data):
        self._key = key
        self._data = data
        self._next = None

    @property
    def key(self):
        return self._key

    @property
    def data(self):
        return self._data

    @data.setter
    def data(self, value):
        self._data = value

    @property
    def next(self):
        return self._next

    @next.setter
    def next(self, entry):
        self._next = entry


class HashLinearProbing:
    def __init__(self, size):
        self._buckets = [-1]*size
        self._size = 0

    @property
    def size(self):
        return self._size

    def _generate_hash(self, value):
        key = value % len(self._buckets)
        return key

    def insert(self, key, value):
        if self.is_full():
            return False

        hash = self._generate_hash(key)
        entry = Entry(key, value)
        if self._buckets[hash] == -1:
            self._buckets[hash] = entry
        else:
            while self._buckets[hash] != -1:
                if hash < len(self._buckets):
                    hash += 1
                if hash == len(self._buckets):
                    hash = 0
            self._buckets[hash] = entry
        self._size += 1
        return True

    def get(self, key):
        if self.is_empty():
            return None

        hash = self._generate_hash(key)
        if self._buckets[hash] == -1:
            return None
        return self._buckets[hash]

    def remove(self, key):
        if self.is_empty():
            return None

        hash = self._generate_hash(key)
        if self._buckets[hash] == -1:
            return None
        entry = self._buckets[hash]
        self._buckets[hash] = -1
        self._size -= 1
        return entry.data

    def search(self, key):
        if self.is_empty():
            return None

        hash = self._generate_hash(key)
        if self._buckets[hash] == -1:
            return None
        return self._buckets[hash].data

    def is_empty(self):
        if self._size == 0:
            return True
        return False

    def is_full(self):
        if self._size == len(self._buckets):
            return True
        return False

    def resize(self, value):
        array = [-1]*value
        self._buckets.extend(array)


class HashChaining:
    def __init__(self, size):
        self._buckets = [-1]*size
        self._size = 0

    @property
    def size(self):
        return self._size

    def _generate_hash(self, value):
        key = value % len(self._buckets)
        return key

    def insert(self, key, value):
        if self.is_full():
            return False

        hash = self._generate_hash(key)
        entry = Entry(key, value)
        if self._buckets[hash] == -1:
            self._buckets[hash] = entry
        else:
            front = self._buckets[hash]
            while front.next != None:
                front = front.next
            front.next = entry
        self._size += 1
        return True

    def get(self, key):
        if self.is_empty():
            return None

        hash = self._generate_hash(key)
        if self._buckets[hash] == -1:
            return None

        front = self._buckets[hash]
        if front.key == key:
            return front
        else:
            while front.next != None:
                if front.key == key:
                    return front
                front = front.next
        return None

    def remove(self, key):
        if self.is_empty():
            return None

        hash = self._generate_hash(key)
        front = self._buckets[hash]
        target = front
        if front == -1:
            return None
        if front.key == key:
            if self._buckets[hash].next:
                self._buckets[hash] = self._buckets[hash].next
            else:
                self._buckets[hash] = -1
        else:
            next_entry = front.next
            while next_entry.next != None:
                if next_entry.key == key:
                    target = next_entry
                    front.next = next_entry.next
                    break
                front = next_entry
                next_entry = next_entry.next
        self._size -= 1
        return target.data

    def search(self, key):
        if self.is_empty():
            return None

        hash = self._generate_hash(key)
        front = self._buckets[hash]
        if front == -1:
            return None
        if front.key == key:
            return front.data
        else:
            while front.next != None:
                if front.key == key:
                    return front.data
                front = front.next

    def is_empty(self):
        if self._size == 0:
            return True
        return False

    def is_full(self):
        if self._size == len(self._buckets):
            return True
        return False
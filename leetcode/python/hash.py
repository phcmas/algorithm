class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [None] * size

    def _hash(self, key):
        return hash(key) % self.size

    def put(self, key, value):
        idx = self._hash(key)
        orig_idx = idx

        while self.table[idx] is not None:
            if self.table[idx][0] == key:
                self.table[idx] = (key, value)  # 기존 값 업데이트
                return

            idx = (idx + 1) % self.size  # 개방 주소법(Linear Probing)
            if idx == orig_idx:
                raise Exception("Hash table is full")

        self.table[idx] = (key, value)

    def get(self, key):
        idx = self._hash(key)
        orig_idx = idx

        while self.table[idx] is not None:
            if self.table[idx][0] == key:
                return self.table[idx][1]

            idx = (idx + 1) % self.size
            if idx == orig_idx:
                break

        return None  # 키를 찾지 못한 경우

    def remove(self, key):
        idx = self._hash(key)
        orig_idx = idx

        while self.table[idx] is not None:
            if self.table[idx][0] == key:
                self.table[idx] = None
                return

            idx = (idx + 1) % self.size
            if idx == orig_idx:
                break

        raise KeyError("Key not found")

    def __str__(self):
        return str(self.table)


# 테스트
ht = HashTable()
ht.put("apple", 10)
ht.put("banana", 20)
ht.put("cherry", 30)
print(ht.get("banana"))  # 20
ht.remove("banana")
print(ht.get("banana"))  # None

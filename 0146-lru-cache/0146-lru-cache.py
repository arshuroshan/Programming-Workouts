class LRUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity
        self.lru_queue = []

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1

        self.lru_queue.remove(key)
        self.lru_queue.insert(0, key)
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:

            self.cache[key] = value
            self.lru_queue.remove(key)
            self.lru_queue.insert(0, key)
        else:
            if len(self.cache) >= self.capacity:
                lru_key = self.lru_queue.pop()
                self.cache.pop(lru_key)
            self.cache[key] = value
            self.lru_queue.insert(0, key)
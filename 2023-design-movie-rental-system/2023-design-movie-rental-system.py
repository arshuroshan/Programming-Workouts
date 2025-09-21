from collections import defaultdict
from sortedcontainers import SortedList

class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.a = defaultdict(SortedList)
        self.p = {}
        for s, m, c in entries:
            self.a[m].add((c, s))
            self.p[(s << 30) | m] = c
        self.r = SortedList()

    def search(self, m: int) -> List[int]:
        return [s for _, s in self.a[m][:5]]

    def rent(self, s: int, m: int) -> None:
        c = self.p[(s << 30) | m]
        self.a[m].remove((c, s))
        self.r.add((c, s, m))

    def drop(self, s: int, m: int) -> None:
        c = self.p[(s << 30) | m]
        self.r.remove((c, s, m))
        self.a[m].add((c, s))

    def report(self) -> List[List[int]]:
        return [[s, m] for _, s, m in self.r[:5]]
from typing import List
from sortedcontainers import SortedList

class TaskManager:
    def __init__(self, tasks: List[List[int]]):
        self.m = {}
        self.s = SortedList()
        for u, t, p in tasks:
            self.add(u, t, p)

    def add(self, u: int, t: int, p: int) -> None:
        self.m[t] = (u, p)
        self.s.add((-p, -t))

    def edit(self, t: int, p: int) -> None:
        u, q = self.m[t]
        self.s.discard((-q, -t))
        self.m[t] = (u, p)
        self.s.add((-p, -t))

    def rmv(self, t: int) -> None:
        _, p = self.m.pop(t)
        self.s.remove((-p, -t))

    def execTop(self) -> int:
        if not self.s:
            return -1
        t = -self.s.pop(0)[1]
        u, _ = self.m.pop(t)
        return u
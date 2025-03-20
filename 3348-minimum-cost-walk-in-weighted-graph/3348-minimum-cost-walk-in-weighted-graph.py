from typing import List

class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int) -> bool:
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return False
        if self.size[root_x] < self.size[root_y]:
            root_x, root_y = root_y, root_x
        self.parent[root_y] = root_x
        self.size[root_x] += self.size[root_y]
        return True


class Solution:
    def minimumCost(
        self, n: int, edges: List[List[int]], query: List[List[int]]
    ) -> List[int]:
        uf = UnionFind(n)
        
        for u, v, _ in edges:
            uf.union(u, v)
        and_values = {}
        for u, v, w in edges:
            root = uf.find(u)
            if root in and_values:
                and_values[root] &= w
            else:
                and_values[root] = w
        
        result = []
        for s, t in query:
            if s == t:
                result.append(0)
                continue
            root_s = uf.find(s)
            root_t = uf.find(t)
            if root_s != root_t:
                result.append(-1)
            else:
                result.append(and_values[root_s])
        return result
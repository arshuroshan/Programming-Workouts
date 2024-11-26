class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indeg = [0] * n
        for u, v in edges:
            indeg[v] += 1
        return next((i for i in range(n) if indeg[i] == 0), -1) if indeg.count(0) == 1 else -1
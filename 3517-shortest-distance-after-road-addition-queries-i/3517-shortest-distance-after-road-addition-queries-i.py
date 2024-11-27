from collections import deque

class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        g = [[i + 1] for i in range(n - 1)]
        ans = []
        
        def bfs(start: int) -> int:
            q = deque([start])
            dist = [-1] * n
            dist[start] = 0
            while q:
                u = q.popleft()
                if u == n - 1:
                    return dist[u]
                for v in g[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)
            return -1
        
        for u, v in queries:
            g[u].append(v)
            ans.append(bfs(0))
            
        return ans
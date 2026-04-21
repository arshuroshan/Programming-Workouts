from collections import defaultdict, Counter, deque
from typing import List

class Solution:
    def minimumHammingDistance(
        self, source: List[int], target: List[int], allowedSwaps: List[List[int]]
    ) -> int:
        n = len(source)
        graph = defaultdict(list)
        
        for a, b in allowedSwaps:
            graph[a].append(b)
            graph[b].append(a)
        
        visited = [False] * n
        ans = 0
        
        for i in range(n):
            if not visited[i]:
                queue = deque([i])
                visited[i] = True
                indices = []
                
                while queue:
                    node = queue.popleft()
                    indices.append(node)
                    for nei in graph[node]:
                        if not visited[nei]:
                            visited[nei] = True
                            queue.append(nei)
                
                count = Counter(source[idx] for idx in indices)
                
                for idx in indices:
                    if count[target[idx]] > 0:
                        count[target[idx]] -= 1
                    else:
                        ans += 1
        
        return ans
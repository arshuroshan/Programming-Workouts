import heapq
from math import inf
from itertools import pairwise

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n, m = len(moveTime), len(moveTime[0])
        
        dist = [[inf] * m for _ in range(n)]
        dist[0][0] = 0
        heap = [(0, 0, 0)]
        directions = (-1, 0, 1, 0, -1)
        
        while heap:
            current_time, i, j = heapq.heappop(heap)
            
            if i == n - 1 and j == m - 1:
                return current_time
            
            if current_time > dist[i][j]:
                continue
                
            for a, b in pairwise(directions):
                x, y = i + a, j + b
                
                if 0 <= x < n and 0 <= y < m:
                    new_time = max(moveTime[x][y], current_time) + ((i + j) % 2 + 1)
                    
                    if new_time < dist[x][y]:
                        dist[x][y] = new_time
                        heapq.heappush(heap, (new_time, x, y))
        
        return dist[-1][-1]
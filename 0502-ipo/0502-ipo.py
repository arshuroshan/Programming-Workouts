import heapq
from typing import List

class Solution:
    def findMaximizedCapital(
        self, k: int, w: int, profits: List[int], capital: List[int]
    ) -> int:
        projects = list(zip(capital, profits))
        heapq.heapify(projects)

        available_projects = []
        
        for _ in range(k):
            while projects and projects[0][0] <= w:
                capital, profit = heapq.heappop(projects)
                heapq.heappush(available_projects, -profit)
            if not available_projects:
                break
            
            w += -heapq.heappop(available_projects)
        
        return w
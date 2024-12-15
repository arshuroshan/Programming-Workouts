from heapq import heappush, heappop
from typing import List

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        def improvement(a, b):
            return (a + 1) / (b + 1) - a / b
        

        heap = [(-improvement(a, b), a, b) for a, b in classes]
        heapq.heapify(heap)
        
        for _ in range(extraStudents):
            imp, a, b = heappop(heap)
            a, b = a + 1, b + 1
            heappush(heap, (-improvement(a, b), a, b))
        
        total_ratio = sum(a / b for _, a, b in heap) / len(classes)
        return total_ratio
from collections import deque, defaultdict
from typing import List

class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for a, b in edges:
            graph[a - 1].append(b - 1)
            graph[b - 1].append(a - 1)
        
        component_max_layers = defaultdict(int)

        for i in range(n):
            if i in component_max_layers:
                continue
                
            queue = deque([i])
            distance = [0] * n
            distance[i] = 1
            max_layer = 1
            root = i
            
            while queue:
                current = queue.popleft()
                root = min(root, current)
                for neighbor in graph[current]:
                    if distance[neighbor] == 0:
                        distance[neighbor] = distance[current] + 1
                        max_layer = max(max_layer, distance[neighbor])
                        queue.append(neighbor)
                    elif abs(distance[neighbor] - distance[current]) != 1:
                        return -1
            
            component_max_layers[root] = max(component_max_layers.get(root, 0), max_layer)
        
        return sum(component_max_layers.values())
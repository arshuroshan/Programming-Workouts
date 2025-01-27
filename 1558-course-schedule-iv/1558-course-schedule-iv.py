class Solution:
    def checkIfPrerequisite(self, n: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        from collections import defaultdict, deque
        
        graph = defaultdict(list)
        reachable = [set() for _ in range(n)]

        for u, v in prerequisites:
            graph[u].append(v)

        def bfs(start):
            queue = deque([start])
            while queue:
                node = queue.popleft()
                for neighbor in graph[node]:
                    if neighbor not in reachable[start]:
                        reachable[start].add(neighbor)
                        queue.append(neighbor)

        for i in range(n):
            bfs(i)

        return [b in reachable[a] for a, b in queries]
class Solution:
    def minimumDiameterAfterMerge(
        self, edges1: List[List[int]], edges2: List[List[int]]
    ) -> int:
        diameter1 = self.findTreeDiameter(edges1)
        diameter2 = self.findTreeDiameter(edges2)
        
        return max(diameter1, diameter2, (diameter1 + 1) // 2 + (diameter2 + 1) // 2 + 1)

    def findTreeDiameter(self, edges: List[List[int]]) -> int:
        def dfs(node: int, parent: int) -> Tuple[int, int]:
            farthest_node, max_dist = node, 0
            for neighbor in graph[node]:
                if neighbor != parent:
                    child_node, child_dist = dfs(neighbor, node)
                    if child_dist + 1 > max_dist:
                        max_dist = child_dist + 1
                        farthest_node = child_node
            return farthest_node, max_dist

        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        start_node, _ = dfs(0, -1)

        _, diameter = dfs(start_node, -1)
        
        return diameter
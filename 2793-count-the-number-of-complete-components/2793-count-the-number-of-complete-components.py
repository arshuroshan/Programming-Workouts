class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        parent = [i for i in range(n)]
        rank = [1] * n
        edge_count = [0] * n
        def find(u: int) -> int:
            if parent[u] != u:
                parent[u] = find(parent[u])
            return parent[u]

        def union(u: int, v: int):
            u_root = find(u)
            v_root = find(v)
            if u_root == v_root:
                edge_count[u_root] += 1
                return
            if rank[u_root] > rank[v_root]:
                parent[v_root] = u_root
                rank[u_root] += rank[v_root]
                edge_count[u_root] += edge_count[v_root] + 1
            else:
                parent[u_root] = v_root
                rank[v_root] += rank[u_root]
                edge_count[v_root] += edge_count[u_root] + 1

        for u, v in edges:
            union(u, v)

        ans = 0
        for i in range(n):
            if parent[i] == i:
                nodes = rank[i]
                edges = edge_count[i]
                if edges == nodes * (nodes - 1) // 2:
                    ans += 1
        return ans
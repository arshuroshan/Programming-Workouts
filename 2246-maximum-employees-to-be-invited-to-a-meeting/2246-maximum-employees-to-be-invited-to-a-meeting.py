class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        def find_cycle_and_length(fa: List[int]) -> int:
            n = len(fa)
            visited = [False] * n
            cycle_len = 0

            for i in range(n):
                if visited[i]:
                    continue

                stack = []
                j = i
                while not visited[j]:
                    stack.append(j)
                    visited[j] = True
                    j = fa[j]

                if j in stack:
                    cycle_start = stack.index(j)
                    cycle_len = max(cycle_len, len(stack) - cycle_start)

            return cycle_len

        def compute_indegree_and_dist(fa: List[int]) -> int:
            n = len(fa)
            indegree = [0] * n
            dist = [1] * n

            for v in fa:
                indegree[v] += 1

            q = deque(i for i in range(n) if indegree[i] == 0)

            while q:
                node = q.popleft()
                dist[fa[node]] = max(dist[fa[node]], dist[node] + 1)
                indegree[fa[node]] -= 1
                if indegree[fa[node]] == 0:
                    q.append(fa[node])

            total_distance = sum(dist[i] for i in range(n) if i == fa[fa[i]])
            return total_distance

        return max(find_cycle_and_length(favorite), compute_indegree_and_dist(favorite))
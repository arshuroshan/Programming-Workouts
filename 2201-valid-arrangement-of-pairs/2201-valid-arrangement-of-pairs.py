import collections

class Solution:
    def validArrangement(self, pairs: list[list[int]]) -> list[list[int]]:
        ans = []
        graph = collections.defaultdict(list)
        outDegree = collections.Counter()
        inDegrees = collections.Counter()

        for start, end in pairs:
            graph[start].append(end)
            outDegree[start] += 1
            inDegrees[end] += 1

        def getStartNode() -> int:
            for u in graph.keys():
                if outDegree[u] - inDegrees[u] == 1:
                    return u
            return pairs[0][0]
        def eulerIterative(u: int) -> None:
            stack = [u]
            while stack:
                node = stack[-1]
                if graph[node]:
                    next_node = graph[node].pop()
                    stack.append(next_node)
                else:
                    stack.pop()
                    if stack:
                        ans.append([stack[-1], node])

        eulerIterative(getStartNode())
        return ans[::-1]
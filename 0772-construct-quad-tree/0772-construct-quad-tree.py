"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def isUniform(a, b, c, d):
            """Check if all elements in the given subgrid are the same."""
            val = grid[a][b]
            for i in range(a, c + 1):
                for j in range(b, d + 1):
                    if grid[i][j] != val:
                        return False, None
            return True, val

        def dfs(a, b, c, d):
            uniform, val = isUniform(a, b, c, d)
            if uniform:
                return Node(val, True, None, None, None, None)
            else:
                midRow = (a + c) // 2
                midCol = (b + d) // 2
                topLeft = dfs(a, b, midRow, midCol)
                topRight = dfs(a, midCol + 1, midRow, d)
                bottomLeft = dfs(midRow + 1, b, c, midCol)
                bottomRight = dfs(midRow + 1, midCol + 1, c, d)
                return Node(
                    1,
                    False,
                    topLeft,
                    topRight,
                    bottomLeft,
                    bottomRight
                )

        return dfs(0, 0, len(grid) - 1, len(grid[0]) - 1)
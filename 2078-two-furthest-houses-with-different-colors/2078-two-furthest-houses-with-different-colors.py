class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        n = len(colors)
        first, last = colors[0], colors[-1]
        if first != last:
            return n - 1
        left = next(i for i in range(n) if colors[i] != first)
        right = next(i for i in range(n - 1, -1, -1) if colors[i] != first)
        return max(n - 1 - left, right)
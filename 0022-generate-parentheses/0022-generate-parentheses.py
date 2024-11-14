class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = [(0, 0, '')]
        ans = []

        while stack:
            l, r, t = stack.pop()

            if l == n and r == n:
                ans.append(t)
                continue

            if l < n:
                stack.append((l + 1, r, t + '('))
            if r < l:
                stack.append((l, r + 1, t + ')'))

        return ans
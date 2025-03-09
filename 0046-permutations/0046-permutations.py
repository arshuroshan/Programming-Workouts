from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        stack = [(0, [False] * n, [])]

        while stack:
            i, vis, t = stack.pop()

            if i == n:
                ans.append(t)
                continue

            for j in range(n):
                if not vis[j]:
                   
                    new_vis = vis.copy()
                    new_vis[j] = True
                    stack.append((i + 1, new_vis, t + [nums[j]]))

        return ans
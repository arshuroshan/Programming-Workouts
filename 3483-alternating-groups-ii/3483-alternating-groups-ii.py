from typing import List

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        ans = 0
        cnt = 1
        for i in range(1, n << 1):
            if colors[i % n] != colors[(i - 1) % n]:
                cnt += 1
            else:
                cnt = 1
            if i >= n and cnt >= k:
                ans += 1

        return ans
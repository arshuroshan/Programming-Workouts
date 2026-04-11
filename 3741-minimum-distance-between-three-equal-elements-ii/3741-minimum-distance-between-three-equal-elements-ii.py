class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        last_two = {}
        ans = float('inf')

        for i, x in enumerate(nums):
            if x in last_two:
                prev, last = last_two[x]
                if prev != -1:
                    ans = min(ans, (i - prev) * 2)
                last_two[x] = [last, i]
            else:
                last_two[x] = [-1, i]

        return -1 if ans == float('inf') else ans
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        res = cur = 0
        for v in nums:
            if v == 0:
                cur += 1
                res += cur
            else:
                cur = 0
        return res

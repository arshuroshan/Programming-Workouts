class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(n - 2):
            if nums[i] == 0:
                nums[i] ^= 1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                ans += 1

        if nums[-2:] != [1, 1]:
            return -1

        return ans
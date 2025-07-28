class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        res = p = 0
        for i in range(1, len(nums) - 1):
            if nums[i] == nums[i + 1]:
                continue
            if nums[i] > nums[p] and nums[i] > nums[i + 1]:
                res += 1
            if nums[i] < nums[p] and nums[i] < nums[i + 1]:
                res += 1
            p = i
        return res

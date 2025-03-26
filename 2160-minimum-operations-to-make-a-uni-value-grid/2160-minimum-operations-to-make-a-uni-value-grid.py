class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        nums = []
        for row in grid:
            nums.extend(row)

        remainder = nums[0] % x
        if any(num % x != remainder for num in nums):
            return -1

        nums.sort()
        median = nums[len(nums) // 2]
        operations = 0
        for num in nums:
            operations += abs(num - median) // x
        
        return operations
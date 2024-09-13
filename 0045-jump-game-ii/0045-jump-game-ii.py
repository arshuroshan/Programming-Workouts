class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        jumps = 0
        last_reached = 0
        max_reach = 0

        for i in range(n - 1):
            max_reach = max(max_reach, i + nums[i])
            if i == last_reached:
                jumps += 1
                last_reached = max_reach

        return jumps
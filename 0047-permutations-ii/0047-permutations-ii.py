class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def backtrack(k):
            if k == n:
                res.append(path[:])
                return
            for i in range(n):
                if used[i] or (i > 0 and nums[i] == nums[i - 1] and not used[i - 1]):
                    continue
                path[k] = nums[i]
                used[i] = True
                backtrack(k + 1)
                used[i] = False

        nums.sort()
        n = len(nums)
        res, path, used = [], [0] * n, [False] * n
        backtrack(0)
        return res

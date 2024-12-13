class Solution:
    def findScore(self, nums: List[int]) -> int:
        indexed_nums = sorted((num, i) for i, num in enumerate(nums))
        vis = [False] * len(nums)
        ans = 0
        
        for num, i in indexed_nums:
            if not vis[i]:
                ans += num
                vis[i] = True
                if i > 0:
                    vis[i - 1] = True
                if i < len(nums) - 1:
                    vis[i + 1] = True
                    
        return ans
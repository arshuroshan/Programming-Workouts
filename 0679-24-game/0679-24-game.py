class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        def dfs(nums):
            if len(nums) == 1:
                return abs(nums[0] - 24) < 1e-6
            for i in range(len(nums)):
                for j in range(len(nums)):
                    if i != j:
                        nxt = [nums[k] for k in range(len(nums)) if k != i and k != j]
                        for op in ops:
                            if op == "/" and nums[j] != 0 and dfs(nxt + [nums[i] / nums[j]]): return True
                            if op == "*" and dfs(nxt + [nums[i] * nums[j]]): return True
                            if op == "+" and dfs(nxt + [nums[i] + nums[j]]): return True
                            if op == "-" and dfs(nxt + [nums[i] - nums[j]]): return True
            return False
        ops = "+-*/"
        return dfs([float(x) for x in cards])

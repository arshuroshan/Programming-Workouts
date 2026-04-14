from math import inf
from typing import List

class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()
        
        n = len(robot)
        m = len(factory)
        
        # dp[i][j] = min cost to fix first i robots using first j factories
        dp = [[inf] * (m + 1) for _ in range(n + 1)]
        
        # Base case: 0 robots = 0 cost
        for j in range(m + 1):
            dp[0][j] = 0
        
        for j in range(1, m + 1):
            pos, cap = factory[j - 1]
            
            for i in range(n + 1):
                # Option 1: skip this factory
                dp[i][j] = dp[i][j - 1]
                
                # Option 2: assign k robots to this factory
                cost = 0
                for k in range(1, min(cap, i) + 1):
                    cost += abs(robot[i - k] - pos)
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost)
        
        return dp[n][m]
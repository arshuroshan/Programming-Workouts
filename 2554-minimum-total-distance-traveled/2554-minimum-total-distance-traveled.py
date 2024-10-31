class Solution:
    def minimumTotalDistance(self, robot: List[int], factory: List[List[int]]) -> int:
        robot.sort()
        factory.sort()

        n = len(robot)
        m = len(factory)
        dp = [[float('inf')] * (m + 1) for _ in range(n + 1)]

        dp[0][0] = 0

        for j in range(1, m + 1):
            for i in range(n + 1):
                dp[i][j] = dp[i][j - 1]

                t = 0
                for k in range(min(i, factory[j - 1][1])):
                    t += abs(robot[i - 1 - k] - factory[j - 1][0])
                    dp[i][j] = min(dp[i][j], dp[i - k - 1][j - 1] + t)

        return dp[n][m]
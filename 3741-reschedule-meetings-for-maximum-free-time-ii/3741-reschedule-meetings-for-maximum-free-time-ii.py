class Solution:
    def maxFreeTime(self, eventTime: int, startTime: list[int], endTime: list[int]) -> int:
        n = len(startTime)
        res = 0
        left = [0] * n
        left[0] = startTime[0]
        for i in range(1, n):
            left[i] = max(left[i - 1], startTime[i] - endTime[i - 1])
        right = [0] * n
        right[-1] = eventTime - endTime[-1]
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], startTime[i + 1] - endTime[i])
        for i in range(n):
            l = left[i] if i == 0 else startTime[i] - endTime[i - 1]
            r = right[i] if i == n - 1 else startTime[i + 1] - endTime[i]
            x = 0
            if (i != 0 and left[i - 1] >= endTime[i] - startTime[i]) or (i != n - 1 and right[i + 1] >= endTime[i] - startTime[i]):
                x = endTime[i] - startTime[i]
            res = max(res, l + x + r)
        return res

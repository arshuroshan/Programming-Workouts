class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        ban = set(banned)
        total, count = 0, 0
        for num in range(1, n + 1):
            if num not in ban:
                if total + num > maxSum:
                    break
                total += num
                count += 1
        return count
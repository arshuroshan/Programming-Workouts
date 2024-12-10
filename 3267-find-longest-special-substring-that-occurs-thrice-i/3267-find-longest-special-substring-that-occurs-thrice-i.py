class Solution:
    def maximumLength(self, s: str) -> int:
        def is_valid(x: int) -> bool:
            count = {}
            i = 0
            while i < n:
                j = i
                while j < n and s[j] == s[i]:
                    j += 1

                group_length = j - i
                char = s[i]
                count[char] = count.get(char, 0) + max(0, group_length - x + 1)
                i = j

            return any(v >= 3 for v in count.values())

        n = len(s)
        left, right = 0, n
        while left < right:
            mid = (left + right + 1) // 2
            if is_valid(mid):
                left = mid
            else:
                right = mid - 1
        return left if left > 0 else -1
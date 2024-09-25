class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import Counter, defaultdict
        
        need = Counter(t)
        window = defaultdict(int)
        left, right = 0, 0
        required = len(need)
        formed = 0
        min_length = float('inf')
        min_left = 0

        while right < len(s):
            char = s[right]
            window[char] += 1

            if char in need and window[char] == need[char]:
                formed += 1

            while left <= right and formed == required:
                char = s[left]

                if right - left + 1 < min_length:
                    min_length = right - left + 1
                    min_left = left

                window[char] -= 1
                if char in need and window[char] < need[char]:
                    formed -= 1
                
                left += 1

            right += 1

        return '' if min_length == float('inf') else s[min_left:min_left + min_length]
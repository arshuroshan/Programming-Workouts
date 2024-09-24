class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_index = {}
        ans = i = 0
        
        for j, c in enumerate(s):
            if c in char_index and char_index[c] >= i:
                i = char_index[c] + 1
            char_index[c] = j
            ans = max(ans, j - i + 1)
        
        return ans
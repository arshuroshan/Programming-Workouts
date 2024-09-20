class Solution:
    def shortestPalindrome(self, s: str) -> str:
        def is_palindrome(prefix):
            return prefix == prefix[::-1]
        
        n = len(s)
        max_length = 0
        for i in range(n):
            if is_palindrome(s[:i + 1]):
                max_length = i + 1
        suffix = s[max_length:]
        prefix = suffix[::-1]
        
        return prefix + s
class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        it = iter(str1)
        for c in str2:
            if not any(d in (c, chr(ord(c) - 1) if c != 'a' else 'z') for d in it):
                return False
        return True
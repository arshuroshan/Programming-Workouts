class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        def is_valid(s, t):
            count = 0
            for i in range(len(s)):
                if s[i] != t[i]:
                    count += 1
                    if count > 2:
                        return False
            return True

        return [s for s in queries if any(is_valid(s, t) for t in dictionary)]
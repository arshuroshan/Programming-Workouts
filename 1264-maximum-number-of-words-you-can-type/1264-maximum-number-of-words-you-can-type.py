class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        b = set(brokenLetters)
        return sum(not any(c in b for c in w) for w in text.split())

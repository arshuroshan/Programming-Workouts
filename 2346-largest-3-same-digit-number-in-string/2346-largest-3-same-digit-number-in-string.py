class Solution:
    def largestGoodInteger(self, num: str) -> str:
        for i in map(str, range(9, -1, -1)):
            if i * 3 in num:
                return i * 3
        return ""

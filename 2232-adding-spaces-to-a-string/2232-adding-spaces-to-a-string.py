class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        res = []
        last_index = 0
        
        for space in spaces:
            res.append(s[last_index:space])
            res.append(" ")
            last_index = space
        
        res.append(s[last_index:])
        return "".join(res)
from collections import defaultdict

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        count = defaultdict(int)
        result = 0
        
        for domino in dominoes:
            key = tuple(sorted(domino))
            result += count[key]
            count[key] += 1
        
        return result
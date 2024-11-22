class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        patterns = {}
        
        for row in matrix:
            normalized = tuple(x ^ row[0] for x in row)

            if normalized in patterns:
                patterns[normalized] += 1
            else:
                patterns[normalized] = 1
        
        return max(patterns.values())

class Solution:
    def canChange(self, start: str, target: str) -> bool:
        i, j, n = 0, 0, len(start)
        
        while i < n or j < n:
            while i < n and start[i] == '_':
                i += 1
            while j < n and target[j] == '_':
                j += 1

            if (i < n) != (j < n):
                return False

            if i < n and (start[i] != target[j] or (start[i] == 'L' and i < j) or (start[i] == 'R' and i > j)):
                return False

            i, j = i + 1, j + 1

        return True
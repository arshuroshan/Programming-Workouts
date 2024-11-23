from typing import List
from collections import deque

class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        m, n = len(box), len(box[0])

        for row in box:
            empty_spot = n - 1
            for col in range(n - 1, -1, -1):
                if row[col] == '*':
                    empty_spot = col - 1
                elif row[col] == '#':
                    row[col], row[empty_spot] = row[empty_spot], row[col]
                    empty_spot -= 1

        rotated_box = [[None] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                rotated_box[j][m - 1 - i] = box[i][j]

        return rotated_box
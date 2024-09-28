class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        sub_boxes = [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                c = board[i][j]
                if c == '.':
                    continue
                if c in rows[i]:
                    return False
                if c in cols[j]:
                    return False
                k = (i // 3) * 3 + (j // 3)
                if c in sub_boxes[k]:
                    return False

                rows[i].add(c)
                cols[j].add(c)
                sub_boxes[k].add(c)

        return True
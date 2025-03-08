class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def backtrack(row):
            if row == n:
                result.append(["".join(row) for row in board])
                return
            
            for col in range(n):
                if not cols[col] and not diag1[row + col] and not diag2[row - col]:
                    board[row][col] = "Q"
                    cols[col] = diag1[row + col] = diag2[row - col] = True

                    backtrack(row + 1)

                    board[row][col] = "."
                    cols[col] = diag1[row + col] = diag2[row - col] = False

        board = [["." for _ in range(n)] for _ in range(n)]
        cols = [False] * n
        diag1 = [False] * (2 * n - 1)
        diag2 = [False] * (2 * n - 1)
        result = []
        backtrack(0)
        return result
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i: int, j: int, k: int) -> bool:
            if k == len(word):
                return True
            if not (0 <= i < m and 0 <= j < n) or board[i][j] != word[k]:
                return False
            
            temp = board[i][j]
            board[i][j] = "#"
            for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if dfs(x, y, k + 1):
                    return True
            board[i][j] = temp
            return False

        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
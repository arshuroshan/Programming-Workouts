class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        target = n * n
        q = deque([(1, 0)])
        vis = {1}

        def get_board_value(x):
            row, col = divmod(x - 1, n)
            if row % 2 == 0:
                return board[n - 1 - row][col]
            else:
                return board[n - 1 - row][n - 1 - col]

        while q:
            pos, moves = q.popleft()
            if pos == target:
                return moves
            for next_pos in range(pos + 1, min(pos + 6, target) + 1):
                board_value = get_board_value(next_pos)
                final_pos = next_pos if board_value == -1 else board_value
                if final_pos not in vis:
                    vis.add(final_pos)
                    q.append((final_pos, moves + 1))
        return -1
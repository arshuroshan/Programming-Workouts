class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        valid_rows = set(range(rows))

        for col in range(cols - 1):
            next_valid_rows = set()
            for row in valid_rows:
                for next_row in (row - 1, row, row + 1):
                    if 0 <= next_row < rows and grid[row][col] < grid[next_row][col + 1]:
                        next_valid_rows.add(next_row)
            
            if not next_valid_rows:
                return col
            
            valid_rows = next_valid_rows
        return cols - 1
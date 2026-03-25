class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = 0
        for row in grid:
            total += sum(row)

        if total % 2 != 0:
            return False

        target = total // 2

        row_sum = 0
        for i in range(len(grid) - 1):
            row_sum += sum(grid[i])
            if row_sum == target:
                return True

        col_sum = [0] * len(grid[0])
        for row in grid:
            for j in range(len(grid[0])):
                col_sum[j] += row[j]

        current = 0
        for j in range(len(col_sum) - 1):
            current += col_sum[j]
            if current == target:
                return True

        return False
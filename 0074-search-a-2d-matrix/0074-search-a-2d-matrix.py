class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows, cols = len(matrix), len(matrix[0])
        
        def get_value(index: int) -> int:
            """Helper function to retrieve the value at a 1D index."""
            row, col = divmod(index, cols)
            return matrix[row][col]
        
        left, right = 0, rows * cols - 1
        while left <= right:
            mid = left + (right - left) // 2
            mid_value = get_value(mid)
            
            if mid_value == target:
                return True
            elif mid_value < target:
                left = mid + 1
            else:
                right = mid - 1
        
        return False

class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        if not encodedText:
            return ""

        cols = len(encodedText) // rows
        
        # Build the matrix
        grid = [encodedText[i * cols:(i + 1) * cols] for i in range(rows)]
        
        result = []
        
        # Traverse diagonally
        for col in range(cols):
            r, c = 0, col
            while r < rows and c < cols:
                result.append(grid[r][c])
                r += 1
                c += 1
        
        return ''.join(result).rstrip()
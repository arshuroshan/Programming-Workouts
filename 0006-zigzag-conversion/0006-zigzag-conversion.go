func convert(s string, numRows int) string {
	if numRows == 1 || numRows >= len(s) {
		return s
	}

	n := len(s)
	result := make([]byte, 0, n)
	cycleLen := 2 * numRows - 2

	for row := 0; row < numRows; row++ {
		for j := row; j < n; j += cycleLen {
			result = append(result, s[j])
			if row > 0 && row < numRows-1 {
				diagonalIdx := j + cycleLen - 2 * row
				if diagonalIdx < n {
					result = append(result, s[diagonalIdx])
				}
			}
		}
	}

	return string(result)
}
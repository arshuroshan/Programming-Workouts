package main

import (
	"fmt"
)

func findKthNumber(n int, k int) int {
	curr := 1
	k-- // Adjust k since we start counting from 1

	for k > 0 {
		count := countNumbers(n, curr)
		if count <= k {
			k -= count
			curr++ // Move to the next lexicographical number
		} else {
			k-- // Go deeper into the current "number" branch
			curr *= 10
		}
	}
	return curr
}

func countNumbers(n int, curr int) int {
	count := 0
	first := curr
	last := curr + 1

	for first <= n {
		count += min(n+1, last) - first
		first *= 10
		last *= 10
	}

	return count
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
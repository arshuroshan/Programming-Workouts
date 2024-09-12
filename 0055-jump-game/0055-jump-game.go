func canJump(nums []int) bool {
	n := len(nums)
	lastGoodIndex := n - 1

	for i := n - 2; i >= 0; i-- {
		if i + nums[i] >= lastGoodIndex {
			lastGoodIndex = i
		}
	}
    
	return lastGoodIndex == 0
}
class Solution {
    public int maxSubArray(int[] nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            currentSum = nums[i] + Math.max(currentSum, 0);

            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }
}
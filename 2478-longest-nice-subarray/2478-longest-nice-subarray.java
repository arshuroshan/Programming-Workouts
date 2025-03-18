class Solution {
    public int longestNiceSubarray(int[] nums) {
        int maxLength = 0;
        int mask = 0;
        int left = 0;

        for (int right = 0; right < nums.length; right++) {
            while ((mask & nums[right]) != 0) {
                mask ^= nums[left];
                left++;
            }

            mask |= nums[right];

            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
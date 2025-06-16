class Solution {
    public int maximumDifference(int[] nums) {
        int maxDiff = -1;
        int minVal = Integer.MAX_VALUE;
        
        for (int num : nums) {
            if (num > minVal) {
                maxDiff = Math.max(maxDiff, num - minVal);
            }
            minVal = Math.min(minVal, num);
        }
        
        return maxDiff;
    }
}
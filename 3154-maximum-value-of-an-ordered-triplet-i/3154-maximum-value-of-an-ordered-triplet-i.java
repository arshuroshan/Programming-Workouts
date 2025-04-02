class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        if (n < 3) return 0;
        
        long maxTriplet = 0;
        int[] maxLeft = new int[n];
        int[] maxDiff = new int[n];
        
        maxLeft[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = Math.max(maxLeft[i-1], nums[i]);
        }
        
        maxDiff[1] = maxLeft[0] - nums[1];
        for (int i = 2; i < n; i++) {
            maxDiff[i] = Math.max(maxDiff[i-1], maxLeft[i-1] - nums[i]);
        }
        
        for (int k = 2; k < n; k++) {
            long current = (long) maxDiff[k-1] * nums[k];
            maxTriplet = Math.max(maxTriplet, current);
        }
        
        return maxTriplet;
    }
}
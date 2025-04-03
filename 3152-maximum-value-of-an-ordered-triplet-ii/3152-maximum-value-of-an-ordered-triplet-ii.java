class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        if (n < 3) return 0;
        
        long maxTriplet = 0;
        int currentMax = nums[0];
        long currentMaxDiff = 0;
        
        for (int i = 1; i < n; i++) {
            long potentialTriplet = currentMaxDiff * nums[i];
            maxTriplet = Math.max(maxTriplet, potentialTriplet);
            
            currentMaxDiff = Math.max(currentMaxDiff, currentMax - nums[i]);
            currentMax = Math.max(currentMax, nums[i]);
        }
        
        return maxTriplet;
    }
}
class Solution {
    public int maxProduct(int[] nums) {
        if (nums.length == 0) return 0;
        
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            int current = nums[i];
            int tempMax = Math.max(current, Math.max(maxSoFar * current, minSoFar * current));
            int tempMin = Math.min(current, Math.min(maxSoFar * current, minSoFar * current));
            
            result = Math.max(result, tempMax);
            
            maxSoFar = tempMax;
            minSoFar = tempMin;
        }
        
        return result;
    }
}
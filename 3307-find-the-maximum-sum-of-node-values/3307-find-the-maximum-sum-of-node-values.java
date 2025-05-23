class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long[] dp = new long[]{0, Long.MIN_VALUE};
        
        for (int num : nums) {
            long xor = num ^ k;
            long[] newDp = new long[2];
            
            newDp[0] = Math.max(dp[0] + num, dp[1] + xor);
            newDp[1] = Math.max(dp[1] + num, dp[0] + xor);
            
            dp = newDp;
        }
        
        return dp[0];
    }
}
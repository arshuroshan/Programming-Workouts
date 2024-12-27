class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int ans = 0;
        int maxSum = values[0];
        
        for (int j = 1; j < values.length; ++j) {
            ans = Math.max(ans, maxSum + values[j] - j);
            maxSum = Math.max(maxSum, values[j] + j); 
        }
        
        return ans;
    }
}
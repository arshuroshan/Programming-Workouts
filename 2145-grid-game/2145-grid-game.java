class Solution {
    public long gridGame(int[][] grid) {
        int n = grid[0].length;
        long[] topPrefixSum = new long[n + 1];
        long[] bottomPrefixSum = new long[n + 1];

        for (int i = 0; i < n; ++i) {
            topPrefixSum[i + 1] = topPrefixSum[i] + grid[0][i];
            bottomPrefixSum[i + 1] = bottomPrefixSum[i] + grid[1][i];
        }

        long ans = Long.MAX_VALUE;

        for (int j = 0; j < n; ++j) {
            long topRemaining = topPrefixSum[n] - topPrefixSum[j + 1];
            long bottomCollected = bottomPrefixSum[j];

            ans = Math.min(ans, Math.max(topRemaining, bottomCollected));
        }

        return ans;
    }
}
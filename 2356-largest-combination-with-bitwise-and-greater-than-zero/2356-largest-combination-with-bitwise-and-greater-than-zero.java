class Solution {
    public int largestCombination(int[] candidates) {
        int maxBits = 0;
        for (int x : candidates) {
            maxBits = Math.max(maxBits, Integer.toBinaryString(x).length());
        }

        int ans = 0;
        for (int i = 0; i < maxBits; i++) {
            int cnt = 0;
            for (int x : candidates) {
                if ((x & (1 << i)) != 0) {
                    cnt++;
                }
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
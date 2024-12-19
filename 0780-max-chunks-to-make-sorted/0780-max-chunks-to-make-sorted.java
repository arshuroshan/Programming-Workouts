class Solution {
    public int maxChunksToSorted(int[] arr) {
        int ans = 0;
        int[] maxAtIndex = new int[arr.length];
        maxAtIndex[0] = arr[0];

        for (int i = 1; i < arr.length; ++i) {
            maxAtIndex[i] = Math.max(maxAtIndex[i - 1], arr[i]);
        }

        for (int i = 0; i < arr.length; ++i) {
            if (maxAtIndex[i] == i) {
                ++ans;
            }
        }

        return ans;
    }
}
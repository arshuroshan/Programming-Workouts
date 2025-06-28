import java.util.*;

class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        Arrays.sort(indices, Comparator.comparingInt(i -> nums[i]));

        Integer[] topKIndices = Arrays.copyOfRange(indices, n - k, n);

        Arrays.sort(topKIndices);

        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = nums[topKIndices[i]];
        }

        return result;
    }
}

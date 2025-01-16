class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        int ans = 0;

        if (nums2.length % 2 == 1) {
            ans = xorArray(nums1);
        }

        if (nums1.length % 2 == 1) {
            ans ^= xorArray(nums2);
        }

        return ans;
    }

    private int xorArray(int[] nums) {
        int result = 0;
        for (int v : nums) {
            result ^= v;
        }
        return result;
    }
}
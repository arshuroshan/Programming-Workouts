class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;

        return (f(nums1, 0, m, nums2, 0, n, (m + n + 1) / 2) +
                f(nums1, 0, m, nums2, 0, n, (m + n + 2) / 2)) / 2.0;
    }

    private int f(int[] nums1, int i, int m, int[] nums2, int j, int n, int k) {
        if (i >= m) {
            return nums2[j + k - 1];
        }
        if (j >= n) {
            return nums1[i + k - 1];
        }
        if (k == 1) {
            return Math.min(nums1[i], nums2[j]);
        }

        int p = k / 2;
        int x = i + p - 1 < m ? nums1[i + p - 1] : Integer.MAX_VALUE;
        int y = j + p - 1 < n ? nums2[j + p - 1] : Integer.MAX_VALUE;

        return x < y ? f(nums1, i + p, m, nums2, j, n, k - p) : f(nums1, i, m, nums2, j + p, n, k - p);
    }
}
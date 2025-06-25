class Solution {
    private int[] nums1;
    private int[] nums2;

    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        
        long left = getInitialLeftBound();
        long right = getInitialRightBound();
        
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (countProductsLessOrEqual(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private long getInitialLeftBound() {
        int max1 = Math.max(Math.abs(nums1[0]), Math.abs(nums1[nums1.length - 1]));
        int max2 = Math.max(Math.abs(nums2[0]), Math.abs(nums2[nums2.length - 1]));
        return (long) -max1 * max2;
    }

    private long getInitialRightBound() {
        int max1 = Math.max(Math.abs(nums1[0]), Math.abs(nums1[nums1.length - 1]));
        int max2 = Math.max(Math.abs(nums2[0]), Math.abs(nums2[nums2.length - 1]));
        return (long) max1 * max2;
    }

    private long countProductsLessOrEqual(long target) {
        long count = 0;
        for (int x : nums1) {
            if (x > 0) {
                count += countPositiveXProducts(x, target);
            } else if (x < 0) {
                count += countNegativeXProducts(x, target);
            } else if (target >= 0) {
                count += nums2.length;
            }
        }
        return count;
    }

    private int countPositiveXProducts(int x, long target) {
        int left = 0, right = nums2.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((long) x * nums2[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private int countNegativeXProducts(int x, long target) {
        int left = 0, right = nums2.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((long) x * nums2[mid] <= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums2.length - left;
    }
}
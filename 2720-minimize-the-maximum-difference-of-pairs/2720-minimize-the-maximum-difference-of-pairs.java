import java.util.Arrays;

class Solution {
    public int minimizeMax(int[] nums, int p) {
        if (p == 0) return 0;
        
        Arrays.sort(nums);
        int left = 0;
        int right = nums[nums.length - 1] - nums[0];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(nums, mid, p)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    private boolean canFormPairs(int[] nums, int threshold, int requiredPairs) {
        int pairsFormed = 0;
        int i = 0;
        while (i < nums.length - 1 && pairsFormed < requiredPairs) {
            if (nums[i + 1] - nums[i] <= threshold) {
                pairsFormed++;
                i += 2;
            } else {
                i++;
            }
        }
        return pairsFormed >= requiredPairs;
    }
}
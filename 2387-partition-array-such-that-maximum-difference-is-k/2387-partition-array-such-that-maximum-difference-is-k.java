import java.util.Arrays;

class Solution {
    public int partitionArray(int[] nums, int k) {
        if (nums.length == 0) return 0;
        
        Arrays.sort(nums);
        int partitions = 1;
        int currentMin = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - currentMin > k) {
                partitions++;
                currentMin = nums[i];
            }
        }
        
        return partitions;
    }
}
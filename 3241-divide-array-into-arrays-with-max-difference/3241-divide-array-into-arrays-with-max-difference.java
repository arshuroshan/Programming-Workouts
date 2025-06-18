import java.util.Arrays;

class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        
        int groupCount = nums.length / 3;
        int[][] result = new int[groupCount][3];
        
        for (int group = 0; group < groupCount; group++) {
            int startIdx = group * 3;
            
            if (nums[startIdx + 2] - nums[startIdx] > k) {
                return new int[0][];
            }
            
            result[group] = new int[] {
                nums[startIdx],
                nums[startIdx + 1], 
                nums[startIdx + 2]
            };
        }
        
        return result;
    }
}
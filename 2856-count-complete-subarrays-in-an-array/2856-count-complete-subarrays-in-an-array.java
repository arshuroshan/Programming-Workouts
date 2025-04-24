class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> distinctElements = new HashSet<>();
        for (int num : nums) {
            distinctElements.add(num);
        }
        int totalDistinct = distinctElements.size();
        
        int count = 0;
        int left = 0;
        Map<Integer, Integer> windowCounts = new HashMap<>();
        
        for (int right = 0; right < nums.length; right++) {
            windowCounts.put(nums[right], windowCounts.getOrDefault(nums[right], 0) + 1);
            
            while (windowCounts.size() == totalDistinct) {
                count += nums.length - right;
                
                int leftNum = nums[left];
                windowCounts.put(leftNum, windowCounts.get(leftNum) - 1);
                if (windowCounts.get(leftNum) == 0) {
                    windowCounts.remove(leftNum);
                }
                left++;
            }
        }
        
        return count;
    }
}
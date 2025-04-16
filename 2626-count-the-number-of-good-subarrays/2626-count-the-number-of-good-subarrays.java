class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        long goodSubarrays = 0;
        int left = 0;
        int currentPairs = 0;
        
        for (int right = 0; right < nums.length; right++) {
            int num = nums[right];
            int count = freq.getOrDefault(num, 0);
            currentPairs += count;
            freq.put(num, count + 1);
            
            while (currentPairs >= k) {
                goodSubarrays += nums.length - right;
                
                int leftNum = nums[left];
                int leftCount = freq.get(leftNum);
                currentPairs -= leftCount - 1;
                freq.put(leftNum, leftCount - 1);
                
                if (freq.get(leftNum) == 0) {
                    freq.remove(leftNum);
                }
                left++;
            }
        }
        
        return goodSubarrays;
    }
}
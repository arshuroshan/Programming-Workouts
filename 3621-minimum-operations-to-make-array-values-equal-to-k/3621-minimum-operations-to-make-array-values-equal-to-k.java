class Solution {
    public int minOperations(int[] nums, int k) {
        int min = Integer.MAX_VALUE;
        Set<Integer> unique = new HashSet<>();
        
        for (int num : nums) {
            if (num < k) {
                return -1;
            }
            if (num >= k) {
                unique.add(num);
                min = Math.min(min, num);
            }
        }
    
        return unique.size() - (min == k ? 1 : 0);
    }
}
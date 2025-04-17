class Solution {
    public int countPairs(int[] nums, int k) {
        Map<Integer, List<Integer>> numIndices = new HashMap<>();
        int count = 0;
        
        for (int j = 0; j < nums.length; j++) {
            int num = nums[j];
            if (numIndices.containsKey(num)) {
                for (int i : numIndices.get(num)) {
                    if ((i * j) % k == 0) {
                        count++;
                    }
                }
            }
            numIndices.computeIfAbsent(num, x -> new ArrayList<>()).add(j);
        }
        
        return count;
    }
}
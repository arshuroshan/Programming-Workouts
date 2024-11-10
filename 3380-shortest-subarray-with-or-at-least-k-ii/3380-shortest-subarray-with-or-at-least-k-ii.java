class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int[] bitCount = new int[32];
        int minLength = n + 1;
        int subarrayOr = 0;
        
        for (int start = 0, end = 0; end < n; ++end) {
            subarrayOr |= nums[end];
            
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[end] & (1 << bit)) != 0) {
                    bitCount[bit]++;
                }
            }

            while (subarrayOr >= k && start <= end) {
                minLength = Math.min(minLength, end - start + 1);
                for (int bit = 0; bit < 32; ++bit) {
                    if ((nums[start] & (1 << bit)) != 0) {
                        bitCount[bit]--;
                        if (bitCount[bit] == 0) {
                            subarrayOr ^= (1 << bit);
                        }
                    }
                }
                start++;
            }
        }
        
        return minLength > n ? -1 : minLength;
    }
}
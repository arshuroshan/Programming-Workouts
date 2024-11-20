class Solution {
    public int takeCharacters(String s, int k) {
        int n = s.length();
        int[] totalCount = new int[3];
        
        for (char ch : s.toCharArray()) {
            totalCount[ch - 'a']++;
        }
        
        for (int count : totalCount) {
            if (count < k) {
                return -1;
            }
        }
        
        int maxLength = 0;
        int[] windowCount = new int[3];
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            windowCount[s.charAt(right) - 'a']++;
            
            while (windowCount[0] > totalCount[0] - k || 
                   windowCount[1] > totalCount[1] - k || 
                   windowCount[2] > totalCount[2] - k) {
                windowCount[s.charAt(left) - 'a']--;
                left++;
            }
            
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return n - maxLength;
    }
}
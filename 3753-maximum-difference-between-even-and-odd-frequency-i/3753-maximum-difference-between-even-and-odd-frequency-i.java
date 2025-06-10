class Solution {
    public int maxDifference(String s) {
        int[] charCounts = new int[26];
        
        for (char c : s.toCharArray()) {
            charCounts[c - 'a']++;
        }
        
        int maxOdd = 0;
        int minEven = Integer.MAX_VALUE;
        
        for (int count : charCounts) {
            if (count == 0) continue;
            
            if (count % 2 != 0) {
                maxOdd = Math.max(maxOdd, count);
            } else {
                minEven = Math.min(minEven, count);
            }
        }
        
        if (minEven == Integer.MAX_VALUE) {
            minEven = 0;
        }
        
        return maxOdd - minEven;
    }
}
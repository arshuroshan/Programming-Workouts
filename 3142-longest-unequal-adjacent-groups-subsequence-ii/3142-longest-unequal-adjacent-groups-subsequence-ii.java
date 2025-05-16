import java.util.*;

class Solution {
    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        int n = words.length;
        int[] dp = new int[n];
        int[] prev = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(prev, -1);
        
        int maxLen = 1;
        int lastIndex = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && 
                    isHammingDistanceOne(words[i], words[j]) && 
                    dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    
                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        lastIndex = i;
                    }
                }
            }
        }
        
        return reconstructSubsequence(words, prev, lastIndex);
    }
    
    private boolean isHammingDistanceOne(String a, String b) {
        if (a.length() != b.length()) return false;
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
                if (diff > 1) return false;
            }
        }
        return diff == 1;
    }
    
    private List<String> reconstructSubsequence(String[] words, int[] prev, int lastIndex) {
        LinkedList<String> result = new LinkedList<>();
        for (int i = lastIndex; i != -1; i = prev[i]) {
            result.addFirst(words[i]);
        }
        return new ArrayList<>(result);
    }
}
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> frequency = new HashMap<>();
        
        for (String word : words) {
            frequency.put(word, frequency.getOrDefault(word, 0) + 1);
        }
        
        int length = 0;
        int centralPair = 0;
        
        for (Map.Entry<String, Integer> entry : frequency.entrySet()) {
            String word = entry.getKey();
            int count = entry.getValue();
            
            if (isDoubleLetter(word)) {
                int pairs = count / 2;
                length += pairs * 4;
                if (count % 2 == 1) {
                    centralPair = 1;
                }
            } else {
                String reversed = reverseWord(word);
                int mirrorCount = frequency.getOrDefault(reversed, 0);
                length += Math.min(count, mirrorCount) * 2;
            }
        }
        
        return length + (centralPair > 0 ? 2 : 0);
    }
    
    private boolean isDoubleLetter(String word) {
        return word.charAt(0) == word.charAt(1);
    }
    
    private String reverseWord(String word) {
        return new StringBuilder(word).reverse().toString();
    }
}
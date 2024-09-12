class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        boolean[] allowedChars = new boolean[26];
    
        for (char c : allowed.toCharArray()) {
            allowedChars[c - 'a'] = true;
        }

        int count = 0;
        for (String word : words) {
            if (isConsistent(word, allowedChars)) {
                count++;
            }
        }
        
        return count;
    }

    private boolean isConsistent(String word, boolean[] allowedChars) {
        for (int i = 0; i < word.length(); i++) {
            if (!allowedChars[word.charAt(i) - 'a']) {
                return false;
            }
        }
        return true;
    }
}

class Solution {

    private int[] getCharCount(String word) {
        int[] count = new int[26];
        for (char c : word.toCharArray()) {
            count[c - 'a']++;
        }
        return count;
    }

    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] maxCount = new int[26];

        for (String word : words2) {
            int[] wordCount = getCharCount(word);
            for (int i = 0; i < 26; i++) {
                maxCount[i] = Math.max(maxCount[i], wordCount[i]);
            }
        }
        
        List<String> result = new ArrayList<>();

        for (String word : words1) {
            int[] wordCount = getCharCount(word);
            boolean isSubset = true;
            for (int i = 0; i < 26; i++) {
                if (wordCount[i] < maxCount[i]) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) {
                result.add(word);
            }
        }
        
        return result;
    }
}
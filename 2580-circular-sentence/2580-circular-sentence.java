class Solution {
    public boolean isCircularSentence(String sentence) {
        String[] words = sentence.split(" ");
        int n = words.length;

        for (int i = 1; i < n; ++i) {
            if (words[i - 1].charAt(words[i - 1].length() - 1) != words[i].charAt(0)) {
                return false;
            }
        }

        return words[n - 1].charAt(words[n - 1].length() - 1) == words[0].charAt(0);
    }
}
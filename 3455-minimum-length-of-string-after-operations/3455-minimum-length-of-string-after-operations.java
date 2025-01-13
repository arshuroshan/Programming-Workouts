class Solution {
    public int minimumLength(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        int result = 0;
        for (int count : freq) {
            if (count > 0) {
                result += (count & 1) == 1 ? 1 : 2;
            }
        }
        return result;
    }
}
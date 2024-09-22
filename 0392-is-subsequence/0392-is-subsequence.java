class Solution {
    public boolean isSubsequence(String s, String t) {
        int sIndex = 0, tIndex = 0;

        while (sIndex < s.length() && tIndex < t.length()) {
            if (isMatch(s.charAt(sIndex), t.charAt(tIndex))) {
                sIndex++;
            }
            tIndex++;
        }

        return sIndex == s.length();
    }

    private boolean isMatch(char sChar, char tChar) {
        return sChar == tChar;
    }
}
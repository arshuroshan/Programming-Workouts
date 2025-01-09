class Solution {
    public int prefixCount(String[] words, String pref) {
        int ans = 0;
        int prefLen = pref.length();
        
        for (String w : words) {
            if (w.length() >= prefLen && w.substring(0, prefLen).equals(pref)) {
                ++ans;
            }
        }
        return ans;
    }
}
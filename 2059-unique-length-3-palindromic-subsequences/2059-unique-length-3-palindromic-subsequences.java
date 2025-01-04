class Solution {
    public int countPalindromicSubsequence(String s) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int first = -1, last = -1;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == c) {
                    if (first == -1) {
                        first = i;
                    } else {
                        last = i;
                    }
                }
            }
            if (last > first + 1) {
                Set<Character> uniqueChars = new HashSet<>();
                for (int i = first + 1; i < last; ++i) {
                    uniqueChars.add(s.charAt(i));
                }
                ans += uniqueChars.size();
            }
        }
        return ans;
    }
}
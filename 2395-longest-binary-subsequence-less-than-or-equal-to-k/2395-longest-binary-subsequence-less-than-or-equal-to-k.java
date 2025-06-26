import java.math.BigInteger;

class Solution {
    public int longestSubsequence(String s, int k) {
        int n = s.length();
        int count = 0;

        StringBuilder sb = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            sb.insert(0, s.charAt(i));
            BigInteger val = new BigInteger(sb.toString(), 2);
            if (val.compareTo(BigInteger.valueOf(k)) <= 0) {
                count++;
            } else if (s.charAt(i) == '0') {
                count++;
            } else {
                sb.deleteCharAt(0);
            }
        }
        return count;
    }
}

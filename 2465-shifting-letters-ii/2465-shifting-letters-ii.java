class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] delta = new int[n + 1];

        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1;
            delta[start] += direction;
            delta[end + 1] -= direction;
        }

        for (int i = 1; i < n; ++i) {
            delta[i] += delta[i - 1];
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            int shift = (c - 'a' + delta[i]) % 26;
            if (shift < 0) {
                shift += 26;
            }
            ans.append((char) ('a' + shift));
        }

        return ans.toString();
    }
}
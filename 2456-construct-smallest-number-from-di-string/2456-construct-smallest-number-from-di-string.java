class Solution {
    public String smallestNumber(String pattern) {
        int n = pattern.length();
        StringBuilder result = new StringBuilder();
        for (int i = 0; i <= n; i++) {
            result.append('0');
        }

        int current = 1;

        for (int i = 0; i <= n; i++) {
            if (i == n || pattern.charAt(i) == 'I') {
                for (int j = i; j >= 0 && result.charAt(j) == '0'; j--) {
                    result.setCharAt(j, (char) ('0' + current));
                    current++;
                }
            }
        }

        return result.toString();
    }
}
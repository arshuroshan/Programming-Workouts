class Solution {
    public String makeFancyString(String s) {
        StringBuilder ans = new StringBuilder();
        int count = 0;
        char prev = '\0';
        
        for (char c : s.toCharArray()) {
            if (c == prev) {
                count++;
            } else {
                count = 1;
                prev = c;
            }
            if (count < 3) {
                ans.append(c);
            }
        }
        return ans.toString();
    }
}
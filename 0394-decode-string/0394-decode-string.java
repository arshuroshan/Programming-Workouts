class Solution {
    private int index = 0;
    
    public String decodeString(String s) {
        StringBuilder result = new StringBuilder();
        int num = 0;
        
        while (index < s.length()) {
            char c = s.charAt(index);
            
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
                index++;
            } else if (c == '[') {
                index++;
                String decoded = decodeString(s);
                result.append(decoded.repeat(num));
                num = 0;
            } else if (c == ']') {
                index++;
                return result.toString();
            } else {
                result.append(c);
                index++;
            }
        }
        
        return result.toString();
    }
}
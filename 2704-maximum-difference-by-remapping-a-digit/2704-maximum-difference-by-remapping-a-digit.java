class Solution {
    public int minMaxDifference(int num) {
        String s = Integer.toString(num);
        
        String minStr = s.replace(s.charAt(0), '0');
        int min = Integer.parseInt(minStr);
        
        char[] maxChars = s.toCharArray();
        for (int i = 0; i < maxChars.length; i++) {
            if (maxChars[i] != '9') {
                char replaceChar = maxChars[i];
                for (int j = i; j < maxChars.length; j++) {
                    if (maxChars[j] == replaceChar) {
                        maxChars[j] = '9';
                    }
                }
                break;
            }
        }
        int max = Integer.parseInt(new String(maxChars));
        
        return max - min;
    }
}
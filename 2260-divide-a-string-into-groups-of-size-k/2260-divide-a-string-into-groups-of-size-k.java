class Solution {
    public String[] divideString(String s, int k, char fill) {
        int segments = (int) Math.ceil((double) s.length() / k);
        String[] result = new String[segments];
        
        int paddingLength = (k - (s.length() % k)) % k;
        String padded = paddingLength > 0 ? 
            s + String.valueOf(fill).repeat(paddingLength) : 
            s;
        
        for (int i = 0; i < segments; i++) {
            int start = i * k;
            int end = Math.min(start + k, padded.length());
            result[i] = padded.substring(start, end);
        }
        
        return result;
    }
}
class Solution {
    public int minimumRecolors(String blocks, int k) {
        int minRecolors = Integer.MAX_VALUE;
        int windowRecolors = 0;
        
        for (int i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') {
                windowRecolors++;
            }
        }
        minRecolors = Math.min(minRecolors, windowRecolors);
        
        for (int i = k; i < blocks.length(); i++) {
            if (blocks.charAt(i) == 'W') {
                windowRecolors++;
            }
            if (blocks.charAt(i - k) == 'W') {
                windowRecolors--;
            }
            minRecolors = Math.min(minRecolors, windowRecolors);
        }
        
        return minRecolors;
    }
}
class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] mapS = new int[256];
        int[] mapT = new int[256];
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            char a = s.charAt(i), b = t.charAt(i);
            
            if (mapS[a] != mapT[b]) {
                return false;
            }
            
            mapS[a] = i + 1;
            mapT[b] = i + 1;
        }
        
        return true;
    }
}
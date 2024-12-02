import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n < 3) return n;
        
        int maxPoints = 1;
        
        for (int i = 0; i < n; ++i) {
            Map<String, Integer> slopeMap = new HashMap<>();
            int duplicate = 1;
            int currentMax = 0;
            
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                if (x1 == x2 && y1 == y2) {
                    duplicate++;
                    continue;
                }
                
                int dx = x2 - x1;
                int dy = y2 - y1;
                int gcd = gcd(dy, dx);
                
                String slope = (dy / gcd) + "/" + (dx / gcd);
                slopeMap.put(slope, slopeMap.getOrDefault(slope, 0) + 1);
                
                currentMax = Math.max(currentMax, slopeMap.get(slope));
            }
            
            maxPoints = Math.max(maxPoints, currentMax + duplicate);
        }
        
        return maxPoints;
    }
    
    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
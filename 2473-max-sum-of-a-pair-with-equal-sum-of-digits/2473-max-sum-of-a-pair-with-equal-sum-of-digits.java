import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maximumSum(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int ans = -1;
        
        for (int v : nums) {
            int sum = digitSum(v);
            if (map.containsKey(sum)) {
                ans = Math.max(ans, map.get(sum) + v);
                map.put(sum, Math.max(map.get(sum), v));
            } else {
                map.put(sum, v);
            }
        }
        
        return ans;
    }
    
    private int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
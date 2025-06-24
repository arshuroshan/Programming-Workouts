import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        int lastAdded = -1;
        
        List<Integer> keyIndices = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                keyIndices.add(i);
            }
        }
        
        for (int keyIdx : keyIndices) {
            int start = Math.max(0, Math.max(keyIdx - k, lastAdded + 1));
            int end = Math.min(n - 1, keyIdx + k);
            
            for (int i = start; i <= end; i++) {
                ans.add(i);
                lastAdded = i;
            }
        }
        
        return ans;
    }
}
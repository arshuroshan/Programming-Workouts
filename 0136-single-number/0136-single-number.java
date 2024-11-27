import java.util.HashSet;

class Solution {
    public int singleNumber(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (!set.add(num)) {
                set.remove(num);
            }
        }
        return set.iterator().next();
    }
}
import java.util.stream.IntStream;

class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int circularDiff = Math.abs(nums[0] - nums[nums.length - 1]);
        int maxAdjacent = IntStream.range(1, nums.length)
            .map(i -> Math.abs(nums[i] - nums[i - 1]))
            .max()
            .orElse(0);
        return Math.max(circularDiff, maxAdjacent);
    }
}
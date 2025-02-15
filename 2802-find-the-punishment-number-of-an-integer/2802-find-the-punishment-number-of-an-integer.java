class Solution {
    public int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            if (canPartition(String.valueOf(square), i)) {
                ans += square;
            }
        }
        return ans;
    }

    private boolean canPartition(String s, int target) {
        return backtrack(s, 0, target, 0);
    }

    private boolean backtrack(String s, int index, int target, int currentSum) {
        if (index == s.length()) {
            return currentSum == target;
        }
        
        int num = 0;
        for (int i = index; i < s.length(); ++i) {
            num = num * 10 + (s.charAt(i) - '0');
            if (currentSum + num > target) {
                break;
            }
            if (backtrack(s, i + 1, target, currentSum + num)) {
                return true;
            }
        }
        return false;
    }
}
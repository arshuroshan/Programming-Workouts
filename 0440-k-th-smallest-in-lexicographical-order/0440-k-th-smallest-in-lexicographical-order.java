class Solution {
    public int findKthNumber(int n, int k) {
        long current = 1;
        k--; // Convert to zero-based index
        
        while (k > 0) {
            long step = calculateSteps(current, current + 1, n);
            
            if (k >= step) {
                current++;
                k -= step;
            } else {
                current *= 10;
                k--;
            }
        }
        
        return (int) current;
    }
    
    private long calculateSteps(long curr, long next, int maxNum) {
        long steps = 0;
        while (curr <= maxNum) {
            steps += Math.min(next, maxNum + 1) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
}
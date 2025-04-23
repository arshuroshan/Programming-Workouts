class Solution {
    public int countLargestGroup(int n) {
        int[] sumCounts = new int[37];
        
        int maxCount = 0;
        int result = 0;
        
        for (int i = 1; i <= n; i++) {
            int digitSum = computeDigitSum(i);
            
            sumCounts[digitSum]++;
            
            if (sumCounts[digitSum] > maxCount) {
                maxCount = sumCounts[digitSum];
                result = 1;
            } else if (sumCounts[digitSum] == maxCount) {
                result++;
            }
        }
        
        return result;
    }
    
    private int computeDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
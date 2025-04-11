class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; num++) {
            if (isSymmetric(num)) {
                count++;
            }
        }
        return count;
    }

    private boolean isSymmetric(int num) {
        String s = Integer.toString(num);
        int length = s.length();
        
        if (length % 2 != 0) return false;
        
        int half = length / 2;
        int firstHalfSum = 0;
        int secondHalfSum = 0;
        
        for (int i = 0; i < half; i++) {
            firstHalfSum += s.charAt(i) - '0';
            secondHalfSum += s.charAt(i + half) - '0';
        }
        
        return firstHalfSum == secondHalfSum;
    }
}
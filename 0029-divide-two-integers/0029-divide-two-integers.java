class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        
        boolean isPositive = (dividend > 0) == (divisor > 0);
        
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        
        int quotient = 0;
        
        while (dividend <= divisor) {
            int tempDivisor = divisor;
            int multiple = 1;
            
            while (tempDivisor >= (Integer.MIN_VALUE >> 1) 
                   && dividend <= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            quotient += multiple;
            dividend -= tempDivisor;
        }
        
        return isPositive ? quotient : -quotient;
    }
}
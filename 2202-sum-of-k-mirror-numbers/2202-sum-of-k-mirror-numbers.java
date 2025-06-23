import java.util.ArrayList;
import java.util.List;

class Solution {
    public long kMirror(int k, int n) {
        long sum = 0;
        int length = 1;
        
        while (n > 0) {
            List<Long> palindromes = generatePalindromes(length);
            
            for (long num : palindromes) {
                if (isPalindromeInBase(num, k)) {
                    sum += num;
                    n--;
                    if (n == 0) break;
                }
            }
            
            length++;
        }
        
        return sum;
    }

    private List<Long> generatePalindromes(int length) {
        List<Long> result = new ArrayList<>();
        int halfLength = (length + 1) / 2;
        long start = (long) Math.pow(10, halfLength - 1);
        long end = (long) Math.pow(10, halfLength);

        for (long i = start; i < end; i++) {
            long palindrome = createPalindrome(i, length % 2 == 0);
            result.add(palindrome);
        }
        
        return result;
    }

    private long createPalindrome(long half, boolean evenDigits) {
        long palindrome = half;
        if (!evenDigits) {
            half /= 10;
        }
        while (half > 0) {
            palindrome = palindrome * 10 + half % 10;
            half /= 10;
        }
        return palindrome;
    }

    private boolean isPalindromeInBase(long num, int base) {
        if (num == 0) return true;
        
        List<Integer> digits = new ArrayList<>();
        while (num > 0) {
            digits.add((int)(num % base));
            num /= base;
        }
        
        int left = 0;
        int right = digits.size() - 1;
        while (left < right) {
            if (!digits.get(left).equals(digits.get(right))) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
}
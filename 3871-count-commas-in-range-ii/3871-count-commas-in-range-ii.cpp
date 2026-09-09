class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long divisor = 1000;

        while (divisor <= n) {
            total += n - divisor + 1;

            if (divisor > n / 1000)
                break;

            divisor *= 1000;
        }

        return total;
    }
};
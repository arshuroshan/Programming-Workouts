class Solution {
public:
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
        
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;
        
        auto mod_pow = [&](long long base, long long exp) -> long long {
            long long result = 1;
            while (exp > 0) {
                if (exp % 2 == 1) {
                    result = (result * base) % MOD;
                }
                base = (base * base) % MOD;
                exp /= 2;
            }
            return result;
        };
        
        long long even_count = mod_pow(5, even_positions);
        long long odd_count = mod_pow(4, odd_positions);
        
        return (even_count * odd_count) % MOD;
    }
};
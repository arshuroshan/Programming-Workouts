class Solution {
    private static final int MAX_N = (int) 1e5 + 10;
    private static final int MOD = (int) 1e9 + 7;
    private static final long[] factorial = new long[MAX_N];
    private static final long[] inverseFactorial = new long[MAX_N];

    static {
        initializeFactorials();
    }

    private static void initializeFactorials() {
        factorial[0] = 1;
        inverseFactorial[0] = 1;
        
        for (int i = 1; i < MAX_N; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
            inverseFactorial[i] = modularInverse(factorial[i], MOD - 2);
        }
    }

    private static long modularInverse(long base, int exponent) {
        long result = 1;
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent >>= 1;
        }
        return result;
    }

    private static long combination(int n, int k) {
        if (k < 0 || k > n) return 0;
        return factorial[n] * inverseFactorial[k] % MOD * inverseFactorial[n - k] % MOD;
    }

    public int countGoodArrays(int n, int m, int k) {
        if (k > n - 1) return 0;
        
        long combinations = combination(n - 1, k);
        long firstTerm = (combinations * m) % MOD;
        long secondTerm = modularInverse(m - 1, n - k - 1);
        
        return (int) (firstTerm * secondTerm % MOD);
    }
}
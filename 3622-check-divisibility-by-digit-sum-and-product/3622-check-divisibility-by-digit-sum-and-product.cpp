class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;

        for (int x = n; x; x /= 10) {
            int digit = x % 10;
            sum += digit;
            product *= digit;
        }

        return n % (sum + product) == 0;
    }
};
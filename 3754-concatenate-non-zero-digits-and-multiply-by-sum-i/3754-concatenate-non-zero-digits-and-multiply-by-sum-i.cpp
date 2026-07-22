class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;
        int sum = 0;

        while (n) {
            int d = n % 10;
            if (d) {
                digits.push_back(d);
                sum += d;
            }
            n /= 10;
        }

        long long value = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            value = value * 10 + digits[i];
        }

        return value * sum;
    }
};
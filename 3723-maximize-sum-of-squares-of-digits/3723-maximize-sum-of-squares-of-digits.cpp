
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) return "";

        string result(num, '0');

        for (int i = 0; i < num && sum > 0; ++i) {
            int digit = min(sum, 9);
            result[i] = '0' + digit;
            sum -= digit;
        }

        return result;
    }
};

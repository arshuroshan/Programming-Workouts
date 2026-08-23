class Solution {
public:
    bool sumGame(string num) {
        int diff = 0, q = 0;
        int n = num.size();

        for (int i = 0; i < n; ++i) {
            int sign = i < n / 2 ? 1 : -1;

            if (num[i] == '?')
                q += sign;
            else
                diff += sign * (num[i] - '0');
        }

        return q % 2 || diff != -9 * q / 2;
    }
};
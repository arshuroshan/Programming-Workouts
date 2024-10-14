class Solution {
public:
    int calculate(string s) {
        return calculateHelper(s, 0).first;
    }
    
    pair<int, int> calculateHelper(const string& s, int i) {
        int ans = 0, sign = 1, num = 0;
        while (i < s.size()) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                ans += sign * num;
                sign = 1;
                num = 0;
            } else if (c == '-') {
                ans += sign * num;
                sign = -1;
                num = 0;
            } else if (c == '(') {
                auto res = calculateHelper(s, i + 1);
                ans += sign * res.first;
                i = res.second;
            } else if (c == ')') {
                ans += sign * num;
                return {ans, i};
            }
            ++i;
        }
        ans += sign * num;
        return {ans, i};
    }
};
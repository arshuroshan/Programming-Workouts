class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len;
        long long cur = 0;

        for (char ch : s) {
            if (ch == '*') cur -= cur > 0;
            else if (ch == '#') cur *= 2;
            else if (ch != '%') ++cur;

            len.push_back(cur);
        }

        if (k >= cur) return '.';

        for (int i = (int)s.size() - 1; i >= 0; --i) {
            char ch = s[i];
            long long before = i ? len[i - 1] : 0;

            if (ch == '#') {
                if (k >= before) k -= before;
                cur = before;
            } 
            else if (ch == '%') {
                k = cur - 1 - k;
            } 
            else if (ch == '*') {
                cur = before;
            } 
            else {
                if (k == before) return ch;
                cur = before;
            }
        }

        return '.';
    }
};
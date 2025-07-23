class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char u = 'a', v = 'b';
        if (x < y) {
            swap(x, y);
            swap(u, v);
        }
        int res = 0, c1 = 0, c2 = 0;
        for (char ch : s) {
            if (ch == u) {
                c1++;
            } else if (ch == v) {
                if (c1) {
                    res += x;
                    c1--;
                } else {
                    c2++;
                }
            } else {
                res += min(c1, c2) * y;
                c1 = 0;
                c2 = 0;
            }
        }
        res += min(c1, c2) * y;
        return res;
    }
};

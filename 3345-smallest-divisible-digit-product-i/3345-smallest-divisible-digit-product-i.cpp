class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int product = 1;
            string s = to_string(n);

            for (char c : s)
                product *= c - '0';

            if (product % t == 0)
                return n;

            n++;
        }
    }
};
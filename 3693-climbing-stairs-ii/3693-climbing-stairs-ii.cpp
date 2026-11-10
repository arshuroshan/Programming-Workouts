
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = 0, c = 0;

        for (int i = 0; i < n; i++) {
            int curr = costs[i] + c + 1;

            if (i >= 1)
                curr = min(curr, costs[i] + b + 4);

            if (i >= 2)
                curr = min(curr, costs[i] + a + 9);

            a = b;
            b = c;
            c = curr;
        }

        return c;
    }
};

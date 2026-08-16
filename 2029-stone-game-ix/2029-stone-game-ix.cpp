class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};
        for (int x : stones)
            cnt[x % 3]++;

        auto win = [&](int a, int b) {
            int c0 = cnt[0], c1 = cnt[a], c2 = cnt[b];

            if (c1 == 0)
                return false;

            --c1;
            int moves = 1 + c0;

            int pairs = min(c1, c2);
            moves += 2 * pairs;
            c1 -= pairs;
            c2 -= pairs;

            if (c1 > 0) {
                --c1;
                ++moves;
            }

            return (moves & 1) && c1 != c2;
        };

        return win(1, 2) || win(2, 1);
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int f[2][2] = {}, r = 0;
        for (int x : nums) {
            x &= 1;
            for (int j = 0; j < 2; j++) {
                int y = (j - x + 2) & 1;
                f[x][y] = f[y][x] + 1;
                r = max(r, f[x][y]);
            }
        }
        return r;
    }
};

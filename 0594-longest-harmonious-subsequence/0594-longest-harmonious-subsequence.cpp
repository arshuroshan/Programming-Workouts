class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int x : nums) ++m[x];
        int res = 0;
        for (auto& p : m)
            if (m.count(p.first + 1))
                res = max(res, p.second + m[p.first + 1]);
        return res;
    }
};

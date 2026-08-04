class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto p = minmax_element(nums.begin(), nums.end());
        vector<bool> seen(*p.second + 1, false);

        for (int x : nums)
            seen[x] = true;

        vector<int> res;
        for (int i = *p.first + 1; i < *p.second; i++)
            if (!seen[i])
                res.push_back(i);

        return res;
    }
};
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;

        for (char c : word)
            freq[c]++;

        vector<int> v;
        for (auto& [_, cnt] : freq)
            v.push_back(cnt);

        sort(v.rbegin(), v.rend());

        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            ans += v[i] * (i / 8 + 1);

        return ans;
    }
};
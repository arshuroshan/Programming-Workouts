class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        int active = std::count(s.begin(), s.end(), '1');
        std::vector<int> gaps;

        for (int i = 0, n = s.size(); i < n;) {
            if (s[i] == '1') {
                ++i;
                continue;
            }

            int j = i;
            while (j < n && s[j] == '0') ++j;
            gaps.push_back(j - i);
            i = j;
        }

        int gain = 0;

        for (int i = 1; i < static_cast<int>(gaps.size()); ++i) {
            gain = std::max(gain, gaps[i - 1] + gaps[i]);
        }

        return active + gain;
    }
};
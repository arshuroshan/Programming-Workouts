class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> left(26, s.size()), right(26, -1);

        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            left[c] = min(left[c], i);
            right[c] = i;
        }

        vector<pair<int, int>> ranges;

        for (int c = 0; c < 26; ++c) {
            if (right[c] == -1) continue;

            int start = left[c];
            int finish = right[c];
            bool valid = true;

            for (int pos = start; pos <= finish; ++pos) {
                int ch = s[pos] - 'a';

                if (left[ch] < start) {
                    valid = false;
                    break;
                }

                finish = max(finish, right[ch]);
            }

            if (valid)
                ranges.push_back({start, finish});
        }

        sort(ranges.begin(), ranges.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.second != b.second)
                     return a.second < b.second;
                 return a.first > b.first;
             });

        vector<string> result;
        int previousEnd = -1;

        for (const auto& range : ranges) {
            if (range.first > previousEnd) {
                result.push_back(
                    s.substr(range.first, range.second - range.first + 1)
                );
                previousEnd = range.second;
            }
        }

        return result;
    }
};
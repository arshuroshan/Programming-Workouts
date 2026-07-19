class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> frequency(26);

        for (char c : s) {
            frequency[c - 'a']++;
        }

        vector<bool> selected(26, false);
        string result;

        for (char c : s) {
            int index = c - 'a';
            frequency[index]--;

            if (selected[index]) {
                continue;
            }

            while (!result.empty() &&
                   result.back() > c &&
                   frequency[result.back() - 'a'] > 0) {
                selected[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            selected[index] = true;
        }

        return result;
    }
};
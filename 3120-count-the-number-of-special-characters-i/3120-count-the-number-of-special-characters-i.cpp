class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;

        for (char c : word) {
            if (islower(c)) lower.insert(c);
            else upper.insert(c);
        }

        int ans = 0;

        for (char c : lower) {
            if (upper.count(toupper(c))) {
                ++ans;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int possibleStringCount(string word) {
        int r = 1;
        for (int i = 1; i < word.size(); i++)
            r += word[i] == word[i - 1];
        return r;
    }
};

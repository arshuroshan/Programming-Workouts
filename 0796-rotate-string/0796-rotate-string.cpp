class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string t = s + s;
        vector<int> lps(goal.size());
        for (int i = 1, j = 0; i < goal.size();) {
            if (goal[i] == goal[j]) lps[i++] = ++j;
            else if (j) j = lps[j - 1];
            else lps[i++] = 0;
        }
        for (int i = 0, j = 0; i < t.size();) {
            if (t[i] == goal[j]) {
                i++; j++;
                if (j == goal.size()) return true;
            } else if (j) j = lps[j - 1];
            else i++;
        }
        return false;
    }
};
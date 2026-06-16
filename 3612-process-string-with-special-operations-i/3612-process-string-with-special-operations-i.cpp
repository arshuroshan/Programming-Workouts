class Solution {
public:
    string processStr(string s) {
        string t;

        for (char c : s) {
            switch (c) {
                case '*':
                    if (!t.empty()) t.erase(t.end() - 1);
                    break;
                case '#':
                    t.append(t);
                    break;
                case '%':
                    reverse(t.begin(), t.end());
                    break;
                default:
                    if (isalpha(c)) t.push_back(c);
            }
        }

        return t;
    }
};
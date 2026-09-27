class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> parts;
        string cur;

        for (char c : s) {
            if (c == '(') {
                parts.push_back(cur);
                cur.clear();
            } 
            else if (c == ')') {
                reverse(cur.begin(), cur.end());
                cur = parts.back() + cur;
                parts.pop_back();
            } 
            else {
                cur += c;
            }
        }

        return cur;
    }
};
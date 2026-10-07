class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (valid(cur)) {
                result.push_back(cur);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < cur.size(); ++i) {
                if (cur[i] != '(' && cur[i] != ')') continue;

                string next = cur.substr(0, i) + cur.substr(i + 1);

                if (visited.insert(next).second) {
                    q.push(next);
                }
            }
        }

        return result;
    }

private:
    bool valid(const string& s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                ++balance;
            } else if (c == ')') {
                if (--balance < 0) return false;
            }
        }

        return balance == 0;
    }
};
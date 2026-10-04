class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        queue<pair<string, pair<int, int>>> q;
        q.push({"", {0, 0}});

        while (!q.empty()) {
            auto [cur, count] = q.front();
            q.pop();

            int open = count.first;
            int close = count.second;

            if (open == n && close == n) {
                result.push_back(cur);
                continue;
            }

            if (open < n)
                q.push({cur + "(", {open + 1, close}});

            if (close < open)
                q.push({cur + ")", {open, close + 1}});
        }

        return result;
    }
};
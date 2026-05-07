class Solution {
public:
    vector<vector<vector<char>>> g;
    unordered_set<string> bad;

    bool build(string cur, string nxt) {
        if (cur.size() == 1) {
            return true;
        }

        if (nxt.size() == cur.size() - 1) {
            return build(nxt, "");
        }

        string state = cur + "|" + nxt;
        if (bad.count(state)) {
            return false;
        }

        int idx = nxt.size();
        int x = cur[idx] - 'A';
        int y = cur[idx + 1] - 'A';

        for (char c : g[x][y]) {
            if (build(cur, nxt + c)) {
                return true;
            }
        }

        bad.insert(state);
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        g.assign(7, vector<vector<char>>(7));

        for (auto &s : allowed) {
            g[s[0] - 'A'][s[1] - 'A'].push_back(s[2]);
        }

        return build(bottom, "");
    }
};
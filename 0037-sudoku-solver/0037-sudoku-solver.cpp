using pii = pair<int, int>;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool r[9][9] = {}, c[9][9] = {}, b[3][3][9] = {}, done = false;
        vector<pii> s;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.') s.emplace_back(i, j);
                else {
                    int v = board[i][j] - '1';
                    r[i][v] = c[j][v] = b[i / 3][j / 3][v] = true;
                }
        function<void(int)> go = [&](int d) {
            if (d == s.size()) { done = true; return; }
            int i = s[d].first, j = s[d].second;
            for (int v = 0; v < 9 && !done; v++)
                if (!r[i][v] && !c[j][v] && !b[i / 3][j / 3][v]) {
                    r[i][v] = c[j][v] = b[i / 3][j / 3][v] = true;
                    board[i][j] = v + '1';
                    go(d + 1);
                    if (!done) r[i][v] = c[j][v] = b[i / 3][j / 3][v] = false;
                }
        };
        go(0);
    }
};

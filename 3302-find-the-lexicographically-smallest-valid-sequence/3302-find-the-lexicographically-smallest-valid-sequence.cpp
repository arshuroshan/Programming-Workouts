class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suffix(m, -1);
        vector<int> result(m);

        int p = n - 1;
        for (int q = m - 1; q >= 0 && p >= 0; --q) {
            while (p >= 0 && word1[p] != word2[q])
                --p;

            if (p >= 0)
                suffix[q] = p--;
        }

        int matched = 0;
        bool changed = false;

        for (int idx = 0; idx < n && matched < m; ++idx) {
            if (word1[idx] == word2[matched]) {
                result[matched++] = idx;
                continue;
            }

            if (!changed && (matched == m - 1 || idx < suffix[matched + 1])) {
                result[matched++] = idx;
                changed = true;
            }
        }

        if (matched != m)
            return {};

        return result;
    }
};
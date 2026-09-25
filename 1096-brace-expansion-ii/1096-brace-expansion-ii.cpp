class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> res = parse(expression);
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> parse(const string& exp) {
        set<string> res{""};
        int n = exp.size();

        for (int i = 0; i < n;) {
            set<string> cur;

            if (exp[i] == '{') {
                int start = ++i;
                int depth = 0;

                while (i < n) {
                    if (exp[i] == '{') depth++;
                    else if (exp[i] == '}') {
                        if (depth == 0) break;
                        depth--;
                    }
                    i++;
                }

                cur = split(exp.substr(start, i - start));
                i++;
            } else {
                string word;
                while (i < n && isalpha(exp[i]))
                    word += exp[i++];

                cur.insert(word);
            }

            set<string> next;
            for (const string& a : res)
                for (const string& b : cur)
                    next.insert(a + b);

            res = move(next);
        }

        return res;
    }

    set<string> split(const string& exp) {
        set<string> res;
        int depth = 0;
        int start = 0;

        for (int i = 0; i <= exp.size(); i++) {
            if (i == exp.size() || (exp[i] == ',' && depth == 0)) {
                set<string> part = parse(exp.substr(start, i - start));
                res.insert(part.begin(), part.end());
                start = i + 1;
            } else if (exp[i] == '{') {
                depth++;
            } else if (exp[i] == '}') {
                depth--;
            }
        }

        return res;
    }
};
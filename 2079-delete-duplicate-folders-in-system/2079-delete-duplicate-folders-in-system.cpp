class Trie {
public:
    unordered_map<string, Trie*> c;
    bool d = false;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* r = new Trie();
        for (auto& p : paths) {
            Trie* cur = r;
            for (auto& s : p) {
                if (!cur->c.count(s)) cur->c[s] = new Trie();
                cur = cur->c[s];
            }
        }

        unordered_map<string, Trie*> m;

        auto t = [&](auto&& t, Trie* n) -> string {
            if (n->c.empty()) return "";
            vector<string> v;
            for (auto& [k, u] : n->c) v.push_back(k + "(" + t(t, u) + ")");
            sort(v.begin(), v.end());
            string s;
            for (auto& e : v) s += e;
            if (m.count(s)) {
                n->d = true;
                m[s]->d = true;
            } else {
                m[s] = n;
            }
            return s;
        };

        t(t, r);

        vector<vector<string>> a;
        vector<string> p;

        auto f = [&](auto&& f, Trie* n) -> void {
            if (n->d) return;
            if (!p.empty()) a.push_back(p);
            for (auto& [k, u] : n->c) {
                p.push_back(k);
                f(f, u);
                p.pop_back();
            }
        };

        f(f, r);
        return a;
    }
};

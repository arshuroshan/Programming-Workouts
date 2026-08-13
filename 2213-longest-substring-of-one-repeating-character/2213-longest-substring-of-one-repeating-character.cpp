class SegmentTree {
    struct Node {
        int pref, suff, best, len;
        char lc, rc;

        Node() : pref(0), suff(0), best(0), len(0), lc(0), rc(0) {}
    };

    vector<Node> tree;
    string s;

    Node merge(const Node& a, const Node& b) {
        if (!a.len) return b;
        if (!b.len) return a;

        Node res;
        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if (a.rc == b.lc) {
            if (a.pref == a.len)
                res.pref += b.pref;

            if (b.suff == b.len)
                res.suff += a.suff;

            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int p, int l, int r) {
        if (l == r) {
            tree[p].len = 1;
            tree[p].pref = tree[p].suff = tree[p].best = 1;
            tree[p].lc = tree[p].rc = s[l];
            return;
        }

        int m = (l + r) / 2;

        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);

        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    void update(int p, int l, int r, int pos, char c) {
        if (l == r) {
            s[pos] = c;
            tree[p].lc = tree[p].rc = c;
            return;
        }

        int m = (l + r) / 2;

        if (pos <= m)
            update(p * 2, l, m, pos, c);
        else
            update(p * 2 + 1, m + 1, r, pos, c);

        tree[p] = merge(tree[p * 2], tree[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[p];

        int m = (l + r) / 2;

        if (qr <= m)
            return query(p * 2, l, m, ql, qr);

        if (ql > m)
            return query(p * 2 + 1, m + 1, r, ql, qr);

        return merge(
            query(p * 2, l, m, ql, qr),
            query(p * 2 + 1, m + 1, r, ql, qr)
        );
    }

public:
    SegmentTree(const string& str) : s(str) {
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int pos, char c) {
        update(1, 0, s.size() - 1, pos, c);
    }

    int query() {
        return tree[1].best;
    }
};

class Solution {
public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        SegmentTree tree(s);
        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); ++i) {
            tree.update(queryIndices[i], queryCharacters[i]);
            ans.push_back(tree.query());
        }

        return ans;
    }
};
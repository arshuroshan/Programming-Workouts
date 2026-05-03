class UF {
public:
    vector<int> par, rankv;
    int comp;

    UF(int n) : par(n), rankv(n, 0), comp(n) {
        iota(par.begin(), par.end(), 0);
    }

    int root(int x) {
        while (par[x] != x) {
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }

    bool merge(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a, b);
        par[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        comp--;
        return true;
    }
};

class Solution {
public:
    int N, K;
    vector<vector<int>> E;

    bool feasible(int x) {
        UF uf(N);

        for (auto &e : E)
            if (e[2] >= x)
                uf.merge(e[0], e[1]);

        int left = K;

        for (auto &e : E) {
            if (left == 0) break;
            if (e[2] * 2 >= x)
                if (uf.merge(e[0], e[1]))
                    left--;
        }

        return uf.comp == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        N = n;
        E = edges;
        K = k;

        UF uf(n);
        int bound = 1e6;

        for (auto &e : edges) {
            if (e[3]) {
                bound = min(bound, e[2]);
                if (!uf.merge(e[0], e[1]))
                    return -1;
            }
        }

        for (auto &e : edges)
            uf.merge(e[0], e[1]);

        if (uf.comp != 1) return -1;

        int lo = 1, hi = bound;

        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (feasible(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};
class Solution {
public:
    struct State {
        long long weight;
        vector<int> ids;
    };

    vector<array<int, 4>> a;
    vector<int> starts;
    vector<vector<State>> memo;
    vector<vector<bool>> seen;
    int n;

    State better(State x, State y) {
        if (x.weight != y.weight)
            return x.weight > y.weight ? x : y;
        return x.ids < y.ids ? x : y;
    }

    State solve(int pos, int left) {
        if (pos == n || left == 0)
            return {0, {}};

        if (seen[pos][left])
            return memo[pos][left];

        seen[pos][left] = true;

        State skip = solve(pos + 1, left);

        int next = upper_bound(
            starts.begin(),
            starts.end(),
            a[pos][1]
        ) - starts.begin();

        State take = solve(next, left - 1);
        take.weight += a[pos][2];

        auto it = lower_bound(take.ids.begin(), take.ids.end(), a[pos][3]);
        take.ids.insert(it, a[pos][3]);

        return memo[pos][left] = better(take, skip);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        a.resize(n);
        starts.resize(n);

        for (int i = 0; i < n; ++i)
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i)
            starts[i] = a[i][0];

        memo.assign(n, vector<State>(5));
        seen.assign(n, vector<bool>(5, false));

        return solve(0, 4).ids;
    }
};
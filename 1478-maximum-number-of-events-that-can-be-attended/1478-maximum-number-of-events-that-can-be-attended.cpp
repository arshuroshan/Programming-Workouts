class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> m;
        int a = INT_MAX, b = 0;
        for (auto& e : events) {
            m[e[0]].push_back(e[1]);
            a = min(a, e[0]);
            b = max(b, e[1]);
        }
        priority_queue<int, vector<int>, greater<int>> q;
        int res = 0;
        for (int i = a; i <= b; i++) {
            while (!q.empty() && q.top() < i) q.pop();
            for (int x : m[i]) q.push(x);
            if (!q.empty()) {
                q.pop();
                res++;
            }
        }
        return res;
    }
};

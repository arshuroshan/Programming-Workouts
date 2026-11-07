
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;
        using P = pair<int, int>;
        using T = tuple<ll, int, int>;

        priority_queue<P, vector<P>, greater<P>> available;
        priority_queue<T, vector<T>, greater<T>> busy;

        int n = servers.size();
        int m = tasks.size();

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);
        ll time = 0;

        for (int i = 0; i < m; i++) {
            time = max(time, (ll)i);

            if (available.empty()) {
                time = max(time, get<0>(busy.top()));
            }

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, index] = busy.top();
                busy.pop();
                available.push({weight, index});
            }

            auto [weight, index] = available.top();
            available.pop();

            ans[i] = index;
            busy.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};

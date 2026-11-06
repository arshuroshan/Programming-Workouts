
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int m = queries.size();
        vector<int> order(m);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int left = 0, right = 0;
        int active = 0;

        for (int idx : order) {
            int end = queries[idx];
            int start = end - x;

            while (right < logs.size() && logs[right][1] <= end) {
                int id = logs[right][0];
                if (freq[id]++ == 0) {
                    active++;
                }
                right++;
            }

            while (left < right && logs[left][1] < start) {
                int id = logs[left][0];
                if (--freq[id] == 0) {
                    active--;
                }
                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};

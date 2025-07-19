class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;
        using ll = long long;
        ll s = 0, pre[m + 1], suf[m + 1];
        priority_queue<int> a;
        for (int i = 1; i <= 2 * n; i++) {
            s += nums[i - 1];
            a.push(nums[i - 1]);
            if (a.size() > n) {
                s -= a.top();
                a.pop();
            }
            pre[i] = s;
        }
        s = 0;
        priority_queue<int, vector<int>, greater<int>> b;
        for (int i = m; i > n; i--) {
            s += nums[i - 1];
            b.push(nums[i - 1]);
            if (b.size() > n) {
                s -= b.top();
                b.pop();
            }
            suf[i] = s;
        }
        ll res = 1e18;
        for (int i = n; i <= 2 * n; i++) res = min(res, pre[i] - suf[i + 1]);
        return res;
    }
};

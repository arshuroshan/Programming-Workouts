class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = endTime.size(), s = 0, a = 0;
        vector<int> v(n + 1);
        v[0] = startTime[0];
        for (int i = 1; i < n; i++) v[i] = startTime[i] - endTime[i - 1];
        v[n] = eventTime - endTime[n - 1];
        for (int i = 0; i <= n; i++) {
            s += v[i];
            if (i >= k) {
                a = max(a, s);
                s -= v[i - k];
            }
        }
        return a;
    }
};

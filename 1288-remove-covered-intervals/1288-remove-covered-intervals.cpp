class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        int remaining = intervals.size();
        int farthest = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] <= farthest) {
                remaining--;
            } else {
                farthest = intervals[i][1];
            }
        }

        return remaining;
    }
};
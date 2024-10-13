class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        int maxVal = INT_MIN;
        vector<int> indices(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i});
            maxVal = max(maxVal, nums[i][0]);
        }

        vector<int> result = {minHeap.top().first, maxVal};
        while (true) {
            auto [minVal, row] = minHeap.top();
            minHeap.pop();
            if (maxVal - minVal < result[1] - result[0]) {
                result = {minVal, maxVal};
            }
            indices[row]++;
            if (indices[row] == nums[row].size()) break;
            int nextVal = nums[row][indices[row]];
            minHeap.push({nextVal, row});
            maxVal = max(maxVal, nextVal);
        }

        return result;
    }
};
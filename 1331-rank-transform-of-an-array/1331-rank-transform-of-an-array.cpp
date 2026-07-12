class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int num : temp) {
            if (!rank.count(num)) {
                rank[num] = r++;
            }
        }

        vector<int> result;
        for (int num : arr) {
            result.push_back(rank[num]);
        }

        return result;
    }
};
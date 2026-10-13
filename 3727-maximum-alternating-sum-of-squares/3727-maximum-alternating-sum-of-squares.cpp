
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> values;
        
        for (int num : nums) {
            values.push_back(1LL * num * num);
        }

        sort(values.begin(), values.end(), greater<long long>());

        long long result = 0;

        for (int i = 0; i < values.size(); i++) {
            if (i < (values.size() + 1) / 2) {
                result += values[i];
            } else {
                result -= values[i];
            }
        }

        return result;
    }
};

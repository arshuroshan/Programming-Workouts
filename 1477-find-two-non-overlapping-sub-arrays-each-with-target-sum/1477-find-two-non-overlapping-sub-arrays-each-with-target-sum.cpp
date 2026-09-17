class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, sum = 0;
        int best = n + 1;
        int result = n + 1;
        vector<int> shortest(n, n + 1);

        for (int right = 0; right < n; ++right) {
            sum += arr[right];

            while (sum > target)
                sum -= arr[left++];

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && shortest[left - 1] <= n)
                    result = min(result, shortest[left - 1] + len);

                best = min(best, len);
            }

            shortest[right] = best;
        }

        return result > n ? -1 : result;
    }
};
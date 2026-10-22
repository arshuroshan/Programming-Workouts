
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = find(nums.begin(), nums.end(), 0) - nums.begin();
        int answer = INT_MAX;

        bool clockwise = true;
        bool counterclockwise = true;

        for (int i = 0; i < n - 1; ++i) {
            int a = (pos + i) % n;
            int b = (a + 1) % n;

            if (nums[a] > nums[b]) {
                clockwise = false;
            }

            int x = (pos - i + n) % n;
            int y = (x - 1 + n) % n;

            if (nums[x] > nums[y]) {
                counterclockwise = false;
            }
        }

        if (clockwise) {
            answer = min(answer, pos);
            answer = min(answer, n - pos + 2);
        }

        if (counterclockwise) {
            answer = min(answer, n - pos);
            answer = min(answer, pos + 2);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long len = 1;
        int idx = 0;
        while (len < k) {
            len *= 2;
            idx++;
        }
        int sum = 0;
        while (len > 1) {
            if (k > len / 2) {
                k -= len / 2;
                sum += operations[idx - 1];
            }
            len /= 2;
            idx--;
        }
        return 'a' + (sum % 26);
    }
};

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);

        for (int d : digits)
            freq[d]++;

        int count = 0;

        for (int num = 100; num <= 998; num += 2) {
            int x = num;
            vector<int> need(10);

            while (x > 0) {
                need[x % 10]++;
                x /= 10;
            }

            bool valid = true;

            for (int d = 0; d < 10; d++) {
                if (need[d] > freq[d]) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                count++;
        }

        return count;
    }
};
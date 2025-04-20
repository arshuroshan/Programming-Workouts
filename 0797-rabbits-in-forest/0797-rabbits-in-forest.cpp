class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> counts(1000, 0);
        for (int x : answers) {
            counts[x]++;
        }
        
        int total = 0;
        for (int x = 0; x < 1000; ++x) {
            if (counts[x] > 0) {
                int group_size = x + 1;
                int groups = (counts[x] + group_size - 1) / group_size;
                total += groups * group_size;
            }
        }
        return total;
    }
};
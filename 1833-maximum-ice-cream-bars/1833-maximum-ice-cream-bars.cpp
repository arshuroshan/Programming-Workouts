class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        long long total = 0;

        for (int i = 0; i < costs.size(); i++) {
            total += costs[i];
            if (total > coins) return i;
        }

        return costs.size();
    }
};
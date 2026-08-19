class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;

        for (const auto& seat : reservedSeats)
            reserved[seat[0]].insert(seat[1]);

        int ans = 2 * (n - reserved.size());

        for (const auto& [row, seats] : reserved) {
            bool left = true, middle = true, right = true;

            for (int seat : seats) {
                if (seat >= 2 && seat <= 5)
                    left = false;
                if (seat >= 4 && seat <= 7)
                    middle = false;
                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};
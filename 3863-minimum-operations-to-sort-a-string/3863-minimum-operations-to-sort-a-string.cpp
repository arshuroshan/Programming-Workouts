
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int smallest = 26, largest = -1;
        bool ordered = true;

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            smallest = min(smallest, c);
            largest = max(largest, c);

            if (i > 0 && s[i] < s[i - 1])
                ordered = false;
        }

        if (ordered)
            return 0;

        if (n == 2)
            return -1;

        if (s.front() - 'a' == smallest ||
            s.back() - 'a' == largest)
            return 1;

        bool found = false;

        for (int i = 1; i + 1 < n; i++) {
            int c = s[i] - 'a';

            if (c == smallest || c == largest) {
                found = true;
                break;
            }
        }

        return found ? 2 : 3;
    }
};

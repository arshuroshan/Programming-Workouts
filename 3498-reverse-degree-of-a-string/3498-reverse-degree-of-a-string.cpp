class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        int position = 1;

        for (char ch : s) {
            result += position * ('z' - ch + 1);
            ++position;
        }

        return result;
    }
};
class Solution {
public:
    bool checkPowersOfThree(int n) {
        if (n == 0) return true;
        if (n % 3 > 1) return false;
        return checkPowersOfThree(n / 3);
    }
};
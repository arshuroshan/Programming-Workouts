
class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool alice = false;

        while (n >= stones && stones > 0) {
            n -= stones;
            stones--;
            alice = !alice;
        }

        return alice;
    }
};

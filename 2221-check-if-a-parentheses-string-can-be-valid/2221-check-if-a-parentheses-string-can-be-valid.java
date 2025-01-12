class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if (n % 2 != 0) {
            return false;
        }

        int openOrUnlocked = 0;
        for (int i = 0; i < n; ++i) {
            if (locked.charAt(i) == '0' || s.charAt(i) == '(') {
                openOrUnlocked++;
            } else {
                openOrUnlocked--;
            }

            if (openOrUnlocked < 0) {
                return false;
            }
        }

        int closeOrUnlocked = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked.charAt(i) == '0' || s.charAt(i) == ')') {
                closeOrUnlocked++;
            } else {
                closeOrUnlocked--;
            }

            if (closeOrUnlocked < 0) {
                return false;
            }
        }

        return true;
    }
}

class Solution {
    public int maximumSwap(int num) {
        char[] digits = Integer.toString(num).toCharArray();
        int[] lastPos = new int[10];
        for (int i = 0; i < digits.length; i++) {
            lastPos[digits[i] - '0'] = i;
        }

        for (int i = 0; i < digits.length; i++) {
            for (int d = 9; d > digits[i] - '0'; d--) {
                if (lastPos[d] > i) {
                    char temp = digits[i];
                    digits[i] = digits[lastPos[d]];
                    digits[lastPos[d]] = temp;

                    return Integer.parseInt(new String(digits));
                }
            }
        }

        return num;
    }
}
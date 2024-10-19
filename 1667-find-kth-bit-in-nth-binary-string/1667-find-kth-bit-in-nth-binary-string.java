class Solution {
    public char findKthBit(int n, int k) {
        boolean flip = false;
        int length = (1 << n) - 1;

        while (n > 1) {
            int mid = length / 2 + 1;
            if (k == mid) {
                return flip ? '0' : '1';
            }
            if (k > mid) {
                k = length - k + 1;
                flip = !flip;
            }
            length /= 2;
            n--;
        }
        return flip ? '1' : '0';
    }
}
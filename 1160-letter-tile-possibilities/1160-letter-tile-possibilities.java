class Solution {
    public int numTilePossibilities(String tiles) {
        int[] count = new int[26];
        for (char c : tiles.toCharArray()) {
            count[c - 'A']++;
        }
        return backtrack(count);
    }

    private int backtrack(int[] count) {
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;
            total++;
            count[i]--;
            total += backtrack(count);
            count[i]++;
        }
        return total;
    }
}
class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, (a, b) -> Integer.compare(a[0], b[0]));
        int n = items.length;
        int m = queries.length;
        int[] ans = new int[m];
        int[][] queriesWithIndex = new int[m][2];

        for (int i = 0; i < m; i++) {
            queriesWithIndex[i][0] = queries[i];
            queriesWithIndex[i][1] = i;
        }

        Arrays.sort(queriesWithIndex, (a, b) -> Integer.compare(a[0], b[0]));

        int i = 0, maxBeauty = 0;

        for (int[] q : queriesWithIndex) {
            int queryValue = q[0];
            int originalIndex = q[1];

            while (i < n && items[i][0] <= queryValue) {
                maxBeauty = Math.max(maxBeauty, items[i][1]);
                i++;
            }

            ans[originalIndex] = maxBeauty;
        }

        return ans;
    }
}
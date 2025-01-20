class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] row = new int[m], col = new int[n];
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                map.put(mat[i][j], i * n + j);
            }
        }
        
        for (int k = 0; k < arr.length; ++k) {
            int idx = map.get(arr[k]);
            int i = idx / n;
            int j = idx % n;
            
            if (++row[i] == n || ++col[j] == m) {
                return k;
            }
        }
        
        return -1;
    }
}
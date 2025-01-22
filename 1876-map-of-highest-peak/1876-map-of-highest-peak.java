class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length, n = isWater[0].length;
        int[][] ans = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    queue.offer(new int[] {i, j});
                } else {
                    ans[i][j] = -1;
                }
            }
        }
        
        int[] dirs = {-1, 0, 1, 0, -1};
        
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int i = cell[0], j = cell[1];
            
            for (int k = 0; k < 4; k++) {
                int ni = i + dirs[k];
                int nj = j + dirs[k + 1];
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && ans[ni][nj] == -1) {
                    ans[ni][nj] = ans[i][j] + 1;
                    queue.offer(new int[] {ni, nj});
                }
            }
        }
        
        return ans;
    }
}
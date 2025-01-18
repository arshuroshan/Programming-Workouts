class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
        pq.offer(new int[] {0, 0, 0});
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!pq.isEmpty()) {
            int[] point = pq.poll();
            int i = point[0], j = point[1], cost = point[2];
            
            if (i == m - 1 && j == n - 1) {
                return cost;
            }
            
            if (visited[i][j]) {
                continue;
            }
            
            visited[i][j] = true;
            
            for (int k = 0; k < 4; ++k) {
                int x = i + directions[k][0], y = j + directions[k][1];
                
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    int newCost = cost + (grid[i][j] != k + 1 ? 1 : 0);
                    pq.offer(new int[] {x, y, newCost});
                }
            }
        }
        return -1;
    }
}
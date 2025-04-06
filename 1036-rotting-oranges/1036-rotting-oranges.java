class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int fresh = 0;
        int time = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    queue.offer(new int[]{i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        if (fresh == 0) return 0;
        
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!queue.isEmpty() && fresh > 0) {
            int size = queue.size();
            time++;
            
            for (int i = 0; i < size; i++) {
                int[] cell = queue.poll();
                for (int[] dir : directions) {
                    int x = cell[0] + dir[0];
                    int y = cell[1] + dir[1];
                    
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        queue.offer(new int[]{x, y});
                        fresh--;
                    }
                }
            }
        }
        
        return fresh == 0 ? time : -1;
    }
}
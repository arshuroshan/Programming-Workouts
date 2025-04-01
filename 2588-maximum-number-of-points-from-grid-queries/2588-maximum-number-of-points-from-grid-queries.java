import java.util.*;

class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length, n = grid[0].length;
        int k = queries.length;
        int[] result = new int[k];
        
        Query[] queryObjects = new Query[k];
        for (int i = 0; i < k; i++) {
            queryObjects[i] = new Query(queries[i], i);
        }
        
        Arrays.sort(queryObjects, (a, b) -> a.value - b.value);
        
        PriorityQueue<Cell> minHeap = new PriorityQueue<>((a, b) -> a.value - b.value);
        minHeap.offer(new Cell(0, 0, grid[0][0]));
        
        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;
        
        int count = 0;
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (Query query : queryObjects) {
            while (!minHeap.isEmpty() && minHeap.peek().value < query.value) {
                Cell current = minHeap.poll();
                count++;
                
                for (int[] dir : directions) {
                    int x = current.row + dir[0];
                    int y = current.col + dir[1];
                    
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                        visited[x][y] = true;
                        minHeap.offer(new Cell(x, y, grid[x][y]));
                    }
                }
            }
            result[query.index] = count;
        }
        
        return result;
    }
    
    class Query {
        int value;
        int index;
        
        public Query(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }
    
    class Cell {
        int row;
        int col;
        int value;
        
        public Cell(int row, int col, int value) {
            this.row = row;
            this.col = col;
            this.value = value;
        }
    }
}
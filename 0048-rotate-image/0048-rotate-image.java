class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        for (int layer = 0; layer < n / 2; layer++) {
            int first = layer;
            int last = n - layer - 1;
            for (int j = first; j < last; j++) {
                int offset = j - first;
                
                int top = matrix[first][j];

                matrix[first][j] = matrix[last - offset][first];

                matrix[last - offset][first] = matrix[last][last - offset];

                matrix[last][last - offset] = matrix[j][last];

                matrix[j][last] = top;
            }
        }
    }
}
import java.util.Arrays;

class Solution {
    private static final int MOD = (int) 1e9 + 7;
    
    public int lengthAfterTransformations(String s, int t) {
        if (t == 0) return s.length();
        
        long[] freq = new long[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        
        long[][] transformationMatrix = buildTransformationMatrix();
        long[][] matrixPower = matrixPower(transformationMatrix, t);
        long[] result = multiplyMatrixVector(matrixPower, freq);
        
        int total = 0;
        for (long count : result) {
            total = (int) ((total + count) % MOD);
        }
        return total;
    }
    
    private long[][] buildTransformationMatrix() {
        long[][] matrix = new long[26][26];
        matrix[0][25] = 1;
        matrix[1][0] = 1;
        matrix[1][25] = 1;
        for (int i = 2; i < 26; i++) {
            matrix[i][i - 1] = 1;
        }
        return matrix;
    }
    
    private long[][] matrixPower(long[][] matrix, int power) {
        int n = matrix.length;
        long[][] result = new long[n][n];
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }
        
        while (power > 0) {
            if ((power & 1) == 1) {
                result = multiplyMatrices(result, matrix);
            }
            matrix = multiplyMatrices(matrix, matrix);
            power >>= 1;
        }
        return result;
    }
    
    private long[][] multiplyMatrices(long[][] a, long[][] b) {
        int n = a.length;
        long[][] res = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }
    
    private long[] multiplyMatrixVector(long[][] matrix, long[] vector) {
        int n = matrix.length;
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] = (res[i] + matrix[i][j] * vector[j]) % MOD;
            }
        }
        return res;
    }
}
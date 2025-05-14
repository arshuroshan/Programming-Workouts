import java.util.List;

class Solution {
    private static final int MOD = (int) 1e9 + 7;
    private static final int ALPHABET_SIZE = 26;

    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        int[] charCounts = new int[ALPHABET_SIZE];
        for (char c : s.toCharArray()) {
            charCounts[c - 'a']++;
        }

        int[][] transformMatrix = buildTransformMatrix(nums);

        int[][] poweredMatrix = matrixPower(transformMatrix, t);

        int[] result = multiplyVectorMatrix(charCounts, poweredMatrix);

        int total = 0;
        for (int count : result) {
            total = (total + count) % MOD;
        }
        return total;
    }

    private int[][] buildTransformMatrix(List<Integer> nums) {
        int[][] matrix = new int[ALPHABET_SIZE][ALPHABET_SIZE];
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            int steps = nums.get(i);
            for (int j = 1; j <= steps; j++) {
                matrix[i][(i + j) % ALPHABET_SIZE] = 1;
            }
        }
        return matrix;
    }

    private int[][] matrixPower(int[][] matrix, int power) {
        int size = matrix.length;
        int[][] result = new int[size][size];
        for (int i = 0; i < size; i++) {
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

    private int[][] multiplyMatrices(int[][] a, int[][] b) {
        int size = a.length;
        int[][] result = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                long sum = 0;
                for (int k = 0; k < size; k++) {
                    sum = (sum + (long) a[i][k] * b[k][j]) % MOD;
                }
                result[i][j] = (int) sum;
            }
        }
        return result;
    }

    private int[] multiplyVectorMatrix(int[] vector, int[][] matrix) {
        int size = vector.length;
        int[] result = new int[size];
        for (int i = 0; i < size; i++) {
            long sum = 0;
            for (int j = 0; j < size; j++) {
                sum = (sum + (long) vector[j] * matrix[j][i]) % MOD;
            }
            result[i] = (int) sum;
        }
        return result;
    }
}
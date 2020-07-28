/**
 *
 * lt:221
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 */

class MaxMatrix {
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        int[][]dp = new int[m][n];
        int maxSize = 0;
        for (int i = 0;i<m;i++) {
            for (int j = 0;j<n;j++) {
                if (matrix[i][j]=='1') {
                    if (i==0||j==0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
                    }
                    maxSize = Math.max(maxSize, dp[i][j]);
                }
            }
        }
        return maxSize*maxSize;
    }

    public int min(int a, int b, int c) {
        return Math.min(Math.min(a,b),c);
    }
}

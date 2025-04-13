int uniquePaths(int m, int n){
    int dp[m][n];

    for (int i = 0; i < m; i++) dp[i][0] = 1; //First column: Only one way to reach any cell (i, 0) — keep moving down.
    for (int j = 0; j < n; j++) dp[0][j] = 1; //First row: Only one way to reach any cell (0, j) — keep moving right.

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1]; //To reach cell (i, j), you can either: Come from above (i-1, j) Or from left (i, j-1)
        }
    }

    return dp[m-1][n-1]; //gives you the total unique paths to reach the bottom-right corner.
}

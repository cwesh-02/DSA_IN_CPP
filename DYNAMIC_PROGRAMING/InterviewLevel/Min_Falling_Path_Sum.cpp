class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (col < 0 || col >= n) return 1e9;

        if (row == m - 1) return dp[row][col] = matrix[row][col];

        if (dp[row][col] != 1e9) return dp[row][col];

        int down = solve(row + 1, col, matrix, dp);
        int downLeft = solve(row + 1, col - 1, matrix, dp);
        int downRight = solve(row + 1, col + 1, matrix, dp);

        return dp[row][col] = matrix[row][col] + min({down, downLeft, downRight});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 1e9));

        int result = INT_MAX;
        for (int col = 0; col < n; col++) {
            result = min(result, solve(0, col, matrix, dp));
        }

        return result;
    }
};
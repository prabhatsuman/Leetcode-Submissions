class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // DP array to store the results
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        
        // Initialize the first row
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
        }
        
        // Fill the DP array
        for (int row = 1; row < n; row++) {
            for (int col = 0; col < m; col++) {
                dp[row][col] = dp[row-1][col] + matrix[row][col];
                if (col > 0) {
                    dp[row][col] = min(dp[row][col], dp[row-1][col-1] + matrix[row][col]);
                }
                if (col < m - 1) {
                    dp[row][col] = min(dp[row][col], dp[row-1][col+1] + matrix[row][col]);
                }
            }
        }
        
        // Find the minimum in the last row
        int ans = *min_element(dp[n-1].begin(), dp[n-1].end());
        
        return ans;
    }
};

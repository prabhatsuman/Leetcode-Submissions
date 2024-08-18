class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Helper function for recursion
        function<int(int,int)> helper = [&](int row, int col) -> int {
            // Base case: When we reach the bottom-right corner
            if (row == n - 1 && col == m - 1) {
                return grid[row][col];
            }

            // If already computed, return the stored result
            if (dp[row][col] != -1) {
                return dp[row][col];
            }

            int ans = INT_MAX;

            // Move Down
            if (row + 1 < n) {
                ans = min(ans, helper(row + 1, col) + grid[row][col]);
            }

            // Move Right
            if (col + 1 < m) {
                ans = min(ans, helper(row, col + 1) + grid[row][col]);
            }

            return dp[row][col] = ans;
        };

        // Start from the top-left corner
        return helper(0, 0);
    }
};

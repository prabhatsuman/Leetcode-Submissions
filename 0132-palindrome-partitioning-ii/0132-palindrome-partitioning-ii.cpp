class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n, -1);  // DP array for memoization
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));  // Palindrome check array
        
        // Helper function to determine the minimum cuts needed
        function<int(int)> helper = [&](int i) {
            if (i == n) return 0;  // If we've reached the end of the string, no more cuts are needed
            
            if (dp[i] != -1) return dp[i];  // Return the result if it's already computed
            
            int minCuts = 1e9;  // Initialize with a large number
            
            for (int j = i; j < n; j++) {
                // Check if the substring s[i..j] is a palindrome
                if (s[i] == s[j] && (j - i <= 1 || palindrome[i+1][j-1])) {
                    palindrome[i][j] = true;
                    minCuts = min(minCuts, 1 + helper(j + 1));
                }
            }
            
            dp[i] = minCuts;
            return dp[i];
        };
        
        return helper(0) - 1;  // Start recursion from the beginning of the string and subtract 1 from the result
    }
};

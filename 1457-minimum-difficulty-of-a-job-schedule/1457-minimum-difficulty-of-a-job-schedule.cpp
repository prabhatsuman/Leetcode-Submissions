class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(d>n)return -1;
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, 1e9));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int days = 1; days <= d; days++) {
                int maxJob = 0;
                for (int k = i - 1; k >= days - 1; k--) {
                    maxJob = max(maxJob, jobDifficulty[k]);
                    dp[i][days] = min(dp[i][days], maxJob + dp[k][days - 1]);
                }
            }
        }
        return dp[n][d];
    }
};
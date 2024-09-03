class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9 + 7;
        int maxLen = min(steps / 2 + 1, arrLen);
        vector<int> dp(maxLen, 0);
        dp[0] = 1;

        for (int step = 1; step <= steps; step++) {
            vector<int> currDp(maxLen, 0);
            for (int i = 0; i < maxLen; i++) {
                int ans = dp[i];

                if (i - 1 >= 0) {
                    ans = (ans + dp[i - 1]) % mod;
                }
                if (i + 1 < maxLen) {
                    ans = (ans + dp[i + 1]) % mod;
                }
                currDp[i] = ans;
            }
            dp = currDp;
        }
        return dp[0];
    }
};

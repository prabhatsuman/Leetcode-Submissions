class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();      
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++) {
            int pile_size = piles[i - 1].size();
            for (int coins = 0; coins <= k; coins++) {
                int current_sum = 0;
                dp[i][coins] = dp[i - 1][coins];

                for (int j = 1; j <= pile_size && j <= coins; j++) {
                    current_sum += piles[i - 1][j - 1];
                    dp[i][coins] = max(dp[i][coins], dp[i - 1][coins - j] + current_sum);
                }
            }
        }

        return dp[n][k];
    }
};

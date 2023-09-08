class Solution
{
    public:
        vector<vector < int>> generate(int n)
        {
            vector<vector <int>> dp(n + 1, vector<int> (n + 1, 0));
            dp[1][1] = 1;
            for (int i = 2; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
            }
            vector<vector <int >> ans;
            for (int i = 1; i <= n; i++)
            {
                vector<int> temp;
                for (int j = 1; j <= n; j++)
                {
                    if (dp[i][j]) temp.push_back(dp[i][j]);
                }
                ans.push_back(temp);
            }
            return ans;
        }
};
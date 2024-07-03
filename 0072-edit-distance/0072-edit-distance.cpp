class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,1e9));
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i)
                {
                    dp[i][j]=min(dp[i][j],1+dp[i-1][j]);

                }
                if(j)
                {
                    dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
                }
                if(i && j)
                {
                    dp[i][j]=min(dp[i][j], (word1[i-1]!=word2[j-1])+dp[i-1][j-1]);
                }
            }

        }
        return dp[n][m];

    }
};
class Solution {
public:
   
    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n+1,1e9);
        vector<vector<bool>> palindrome(n,vector<bool>(n,false));
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                
                if(s[i]==s[j] && (i+1>j-1 || palindrome[i+1][j-1]))
                {
                    palindrome[i][j]=true;
                    dp[i]=min(dp[i],dp[j+1]+1);
                }
            }
        }
        return dp[0]-1;
    }
};
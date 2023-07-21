class Solution {
public:
    vector<int> squares;
    int helper(int n,vector<int> &dp)
    {
        if(n==0)
        {
            return 0;
        }
        if(n<0)
        {
            return 1e9;
        }
        if(dp[n]!=-1)return dp[n];
        int ans=1e9;
        for(auto it: squares)
        {
            ans=min(ans,helper(n-it,dp)+1);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        int i=1;
        while(i*i<=n)
        {
            squares.push_back(i*i);
            i++;
        }
        vector<int> dp(n+1,-1);
        
        return helper(n,dp);
        
    }
};
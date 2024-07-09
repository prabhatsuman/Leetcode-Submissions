class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        memset(dp,-1,sizeof(dp));
        function<int(int,int)> helper=[&](int ind,int amount)
        {
            if(amount==0)return 0;
            
            if(ind==coins.size())
            {
                return (int)1e9;
            }
            if(dp[ind][amount]!=-1)return dp[ind][amount];
            int notPick=helper(ind+1,amount);
            
            int pick=1e9;
            if(amount-coins[ind]>=0){
            
                pick=helper(ind,amount-coins[ind])+1;
            }
            return dp[ind][amount]=min(pick,notPick);
        };
        int ans=helper(0,amount);
        return ans==1e9?-1:ans;
    }
};
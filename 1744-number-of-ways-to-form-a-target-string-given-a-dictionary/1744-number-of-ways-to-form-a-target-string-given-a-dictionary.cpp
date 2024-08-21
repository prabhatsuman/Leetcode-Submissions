class Solution {
public:
    const int mod=1e9+7;
    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int m=words[0].size();
        vector<map<char,int>> mp(m);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i][words[j][i]]++;
            }
        }
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));

      
        //ind1 for words , ind2 for target
        function<int(int,int)> helper=[&](int ind1,int ind2 )
        {
            if(ind2==target.size())
            {
                return 1;
            }
            if(ind1==m)
            {
                return 0;
            }
            if(dp[ind1][ind2]!=-1)
            {
                return dp[ind1][ind2];
            }
            int ans=helper(ind1+1,ind2);
            if(mp[ind1].count(target[ind2]))
            {
                ans=((ans+((1LL*mp[ind1][target[ind2]]*helper(ind1+1,ind2+1)))%mod))%mod;
            }
            return dp[ind1][ind2]=ans;
        };
        return helper(0,0);
    }
};
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        vector<pair<int,int>> v;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)    
        {
            for(int j=0;j<m;j++)
            {
                v.push_back({grid[i][j],i});
            }
        }
        sort(v.rbegin(),v.rend());
        int dp[101][(1<<11-1)];
        memset(dp,-1,sizeof(dp));
        function<int(int,int)> helper=[&](int ind,int mask)
        {
            if(ind==v.size())
            {
                return 0;
            }
            if(dp[ind][mask]!=-1)
            {
                return dp[ind][mask];
            }
            int notPick=helper(ind+1,mask);
            int pick=0;
            if(!(mask&(1<<v[ind].second)))
            {
                int curr=v[ind].first;
                int curr_row=v[ind].second;
                while(ind<v.size() && v[ind].first==curr)ind++;
                pick=helper(ind,mask|(1<<curr_row))+curr;
            }
            return dp[ind][mask]=max(pick,notPick);
        };
        return helper(0,0);

        
    }
};
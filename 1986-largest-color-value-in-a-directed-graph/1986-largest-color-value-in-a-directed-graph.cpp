class Solution {
public:
    int largestPathValue(string s, vector<vector<int>>& edges) {
        int n=s.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
           
        }
        vector<vector<int>> dp(n,vector<int>(26,0));
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                dp[i][s[i]-'a']=1;
            }
        }
        int vis=0;
        while(!q.empty())
        {
            int par=q.front();
            q.pop();
            vis++;

            for(auto child:adj[par])
            {
                for(int i=0;i<26;i++)
                {
                    dp[child][i]=max(dp[child][i],dp[par][i]+(s[child]-'a'==i?1:0));
                }
                indegree[child]--;
                if(indegree[child]==0)
                {
                    q.push(child);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {            
                ans=max(ans,dp[i][j]);
            }
        }
        return vis==n?ans:-1;
    }
};
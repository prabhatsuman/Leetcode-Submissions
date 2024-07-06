class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
       
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto child:adj[x])
            {
                indegree[child]--;
                if(indegree[child]==0)
                {
                    q.push(child);
                    ans.push_back(child);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
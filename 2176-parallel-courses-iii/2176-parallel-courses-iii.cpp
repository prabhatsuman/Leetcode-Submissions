class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> dp(n + 1, 0);
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for (auto it : relations) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0)
            {
                q.push(i);
                dp[i]=time[i-1];

            }
        }
        int ans = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
          
            
            for (auto child : adj[node]) {
                indegree[child]--;
                dp[child] = max(dp[child],dp[node]);
                if (indegree[child] == 0)
                {
                    dp[child]=dp[child]+time[child-1];
                    q.push(child);
                }
            }
        }
        // int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (outdegree[i] == 0) {
                // cout << dp[i] << " ";
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
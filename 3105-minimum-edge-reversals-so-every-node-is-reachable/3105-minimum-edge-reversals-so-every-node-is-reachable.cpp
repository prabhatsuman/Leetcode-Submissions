class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], 0});
            adj[it[1]].push_back({it[0], 1});
        }
        vector<int> dp(n, 0);
        function<void(int, int)> dfs = [&](int node, int par) {
            for (auto it : adj[node]) {
                if (it.first == par)
                    continue;
                dfs(it.first, node);
                dp[node] += dp[it.first] + it.second;
            }
        };
        function<void(int, int)> dfs1 = [&](int node, int par) {
            for (auto it : adj[node]) {
                if (it.first == par)
                    continue;
                dp[it.first] +=
                    dp[node] - dp[it.first] - (it.second) + (!it.second);
                dfs1(it.first, node);
            }
        };
        dfs(0, -1);
        dfs1(0, -1);
        return dp;
    }
};
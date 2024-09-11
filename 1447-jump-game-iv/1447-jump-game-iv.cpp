class Solution {
public:
    int minJumps(vector<int>& arr) {       
        int n = arr.size();     
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int ans = 0;
        vector<int> vis(n, false);
        vis[0] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                if (node == n - 1) {
                    return ans;
                }
                if (node - 1 >= 0 && !vis[node - 1]) {
                    vis[node - 1] = true;
                    q.push(node - 1);
                }
                if (node + 1 < n && !vis[node + 1]) {
                    vis[node + 1] = true;
                    q.push(node + 1);
                }
                
                for (int j = 0; j < mp[arr[node]].size(); j++) {
                    if (!vis[mp[arr[node]][j]]) {
                        vis[mp[arr[node]][j]] = true;
                        q.push(mp[arr[node]][j]);
                    }
                }
                mp[arr[node]].clear();
            }
            ans++;
        }
        return -1;
    }
};
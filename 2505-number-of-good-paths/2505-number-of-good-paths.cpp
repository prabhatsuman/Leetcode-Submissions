class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findPar(parent[u]);
    }
    void unionBySize(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);
        if (parU == parV) {
            return;
        }
        if (size[parU] < size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        } else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        DSU ds(n);
        vector<vector<int>> adj(n);
        map<int, vector<int>> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mp[vals[i]].push_back(i);
        }
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for (auto [cost, temp] : mp) {

            for (auto node : temp) {
                for (auto child : adj[node]) {
                    if (vals[child] <= cost) {
                        ds.unionBySize(child, node);
                    }
                }
            }
            unordered_map<int, int> comp;

            for (auto it : temp) {
                comp[ds.findPar(it)]++;
            }
            for (auto [node, size] : comp) {
                ans += (size) * (size - 1) / 2;
            }
        }
        return ans+n;
    }
};
class DSU {
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
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
        }
        else
        {
            parent[parV]=parU;
            size[parU]+=size[parV];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j])
                    continue;
                int curr = i * n + j;
                for (int k = 0; k < 4; k++) {
                    if (i + dx[k] >= 0 && j + dy[k] >= 0 && i + dx[k] < n &&
                        j + dy[k] < n && grid[i + dx[k]][j + dy[k]]) {
                        int newR = i + dx[k], newC = j + dy[k];
                        int newNode = newR * n + newC;
                        ds.unionBySize(curr, newNode);
                    }
                }
            }
        }
        int ans = *max_element(ds.size.begin(), ds.size.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set<int> st;
                if (!grid[i][j]) {                    
                    for (int k = 0; k < 4; k++) {
                        if (i + dx[k] >= 0 && j + dy[k] >= 0 && i + dx[k] < n &&
                            j + dy[k] < n && grid[i + dx[k]][j + dy[k]]) {
                            int newR = i + dx[k], newC = j + dy[k];
                            int newNode = newR * n + newC;
                            st.insert(ds.findPar(newNode));
                        }
                    }
                    int sum=0;
                    for(auto it:st)
                    {
                        sum+=ds.size[it];
                    }
                    ans=max(ans,sum+1);
                }
            }
        }
        return ans;
    }

};
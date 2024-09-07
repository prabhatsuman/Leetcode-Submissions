
class DSU
{
public:
    vector<int> parent, rank, size;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int x = findPar(u);
        int y = findPar(v);
        if (x == y)
            return;
        if (rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else if (rank[y] > rank[x])
        {
            parent[x] = y;
        }
        else
        {
            parent[x] = y;
            rank[y]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int x = findPar(u);
        int y = findPar(v);
        if (x == y)
            return;
        if (size[x] > size[y])
        {
            parent[y] = x;
            size[x] += size[y];
        }
        else
        {
            parent[x] = y;
            size[y] += size[x];
        }
    }
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        map<int,vector<pair<int,int>>> mp;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mp[matrix[i][j]].push_back({i,j});
            }
        }
        vector<int> row(n,0), col(m,0);
        vector<int> rank(n+m,0);
        vector<vector<int>> ans(n,vector<int> (m,0));
        for(auto [val,v]:mp)
        {
            DSU ds(n+m);
            for(auto [x,y]:v)
            {
                ds.unionByRank(x,y+n);
            }
            for(auto [x,y]:v)
            {
                rank[ds.findPar(x)]=max({rank[ds.findPar(x)],row[x],col[y]});
            }
            for(auto [x,y]:v)
            {
                ans[x][y]=row[x]=col[y]=rank[ds.findPar(x)]+1;
            }
        }
        return ans;
    }
};
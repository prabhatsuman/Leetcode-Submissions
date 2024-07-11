class DSU {
    vector<int> parent, rank, size;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n,1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;            
        }
    }
    int findpar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }
    void Union(int u, int v) {
        int x = findpar(u);
        int y = findpar(v);
        if (x == y)
            return;
        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else if (rank[y] > rank[x]) {
            parent[x] = y;
        } else {
            parent[x] = y;
            rank[y]++;
        }
    }
    void Union_size(int u, int v) {
        int x = findpar(u);
        int y = findpar(v);
        if (x == y)
            return;
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
    }
    int longestSubsequence()
    {
        int mx=0;
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]==i)
            {
                mx=max(mx,size[i]);
            }
        }
        return mx;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DSU ds(nums.size());
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i]))
                continue;

            mp[nums[i]] = i;
            if (mp.count(nums[i] - 1)) {
                ds.Union_size(mp[nums[i]], mp[nums[i] - 1]);
            }
            if (mp.count(nums[i] + 1)) {
                ds.Union_size(mp[nums[i]], mp[nums[i] + 1]);
            }
        }
        return ds.longestSubsequence();
    }
};
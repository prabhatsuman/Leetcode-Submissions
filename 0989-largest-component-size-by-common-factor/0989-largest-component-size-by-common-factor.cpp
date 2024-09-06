
class DSU {
public:
    vector<int> parent, rank, size;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int x = findPar(u);
        int y = findPar(v);
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
    void unionBySize(int u, int v) {
        int x = findPar(u);
        int y = findPar(v);
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
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        DSU ds(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 2; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    if (mp.count(j)) {
                        ds.unionBySize(mp[j], i);
                    } else {
                        mp[j] = i;
                    }
                    if (mp.count(nums[i] / j)) {
                        ds.unionBySize(mp[nums[i] / j], i);
                    } else {
                        mp[nums[i] / j] = i;
                    }
                }
            }
            if(mp.count(nums[i]))
            {
                ds.unionBySize(mp[nums[i]],i);
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, ds.size[ds.findPar(i)]);
        }
        return ans;
    }
};
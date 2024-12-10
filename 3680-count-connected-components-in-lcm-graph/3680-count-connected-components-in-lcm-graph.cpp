class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
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
        if (parU == parV)
            return;

        if (size[parU] > size[parV]) {
            parent[parV] = parent[parU];
            size[parU] += size[parV];
        } else {
            parent[parU] = parent[parV];
            size[parV] += size[parU];
        }
    }
};

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        DSU ds(threshold + 1);

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num > threshold)
                continue;
            for (int j = num; j <= threshold; j += num) {
                ds.unionBySize(j, num);
            }
        }
        set<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > threshold)
                ans++;
            else
                st.insert(ds.findPar(nums[i]));
        }
        return ans + st.size();
    }
};
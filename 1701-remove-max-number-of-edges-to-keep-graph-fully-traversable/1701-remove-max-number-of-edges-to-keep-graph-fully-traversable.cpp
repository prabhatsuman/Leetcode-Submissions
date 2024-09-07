class DSU {
public:
    vector<int> parent, rank, size;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    bool unionBySize(int u, int v) {
        int x = findPar(u);
        int y = findPar(v);
        if (x == y)
            return false;
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int count = 0;
        DSU bob(n), alice(n);
        // Process type 3 edges first
        for (auto it : edges) {
            if (it[0] == 3) {
                if (bob.unionBySize(it[1], it[2]) | alice.unionBySize(it[1], it[2])) {
                    count++;
                }
            }
        }
        // Process type 1 edges for Alice
        for (auto it : edges) {
            if (it[0] == 1) {
                if (alice.unionBySize(it[1], it[2])) {
                    count++;
                }
            }
        }
        // Process type 2 edges for Bob
        for (auto it : edges) {
            if (it[0] == 2) {
                if (bob.unionBySize(it[1], it[2])) {
                    count++;
                }
            }
        }
        
        // Check if both Alice and Bob have fully connected graphs
        int aliceComponents = 0, bobComponents = 0;
        for (int i = 1; i <= n; i++) {
            if (alice.findPar(i) == i) aliceComponents++;
            if (bob.findPar(i) == i) bobComponents++;
        }
        
        // If either graph is not fully connected, return -1
        if (aliceComponents != 1 || bobComponents != 1) return -1;
        
        // Return the number of removable edges
        return edges.size() - count;
    }
};

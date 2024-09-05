class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>> vis(n, vector<int>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i==n-1 || j==m-1) {
                    pq.push({heightMap[i][j], i, j});
                    vis[i][j] = true;
                }
            }
        }
        
        int ans = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto wall = pq.top();
            pq.pop();
            int height = wall[0];
            int x = wall[1];
            int y = wall[2];       
            
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m ||
                    vis[newX][newY])
                    continue;
                vis[newX][newY]=true;
                
                ans += max(0, height - heightMap[newX][newY]);
                pq.push({max(heightMap[newX][newY],height), newX, newY});
            }
        }
        return ans;
    }
};
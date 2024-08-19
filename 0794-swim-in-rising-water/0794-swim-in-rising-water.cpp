class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n+1,vector<bool> (m+1,false));
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]=true;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int elevation=it[0],row=it[1],col=it[2];
            if(row==n-1 && col==m-1)
            {
                return elevation;
            }
            for(int ind=0;ind<4;ind++)
            {
                if(row+dx[ind]>=0 && col+dy[ind]>=0 && row+dx[ind]<n && col+dy[ind]<m && !vis[row+dx[ind]][col+dy[ind]])
                {
                    int adjRow=row+dx[ind],adjCol=col+dy[ind];
                    vis[adjRow][adjCol]=true;                    
                    pq.push({max(elevation,grid[adjRow][adjCol]),adjRow,adjCol});
                }
            }
        }
        return -1;
    }
};
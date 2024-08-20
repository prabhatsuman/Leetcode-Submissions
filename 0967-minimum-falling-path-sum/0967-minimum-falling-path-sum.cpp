class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp (n+1,vector<int>(m+1,-1e9) );
        function<int(int,int)> helper =[&](int row,int col)
        {
            if(row==n-1)
            {
                return matrix[row][col];
            }
            if(dp[row][col]!=-1e9)
            {
                return dp[row][col];
            }
            int ans=1e9;
            if(row+1<n)
            {
                ans=min(ans,helper(row+1,col)+matrix[row][col]);
                if(col+1<m)
                {
                    ans=min(ans,helper(row+1,col+1)+matrix[row][col]);
                }
                if(col-1>=0)
                {
                    ans=min(ans,helper(row+1,col-1)+matrix[row][col]);
                }
            }
            return dp[row][col]=ans;
        };
        int ans=1e9;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,helper(0,i));
        }
        return ans;
    }
};
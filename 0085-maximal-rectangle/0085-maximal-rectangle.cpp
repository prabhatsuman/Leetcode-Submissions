class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                ans = max(ans, width * height);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> pre(n,vector<int> (m,0));
        for(int col=0;col<m;col++)
        {
            int sum=0;
            for(int row=0;row<n;row++)
            {
                if(matrix[row][col]=='1')sum++;
                else sum=0;
                pre[row][col]=sum;
            }
        }
        int maxA=0;
        for(int i=0;i<n;i++)
        {
            maxA=max(maxA,largestRectangleArea(pre[i]));
        }
        return maxA;


    }
};
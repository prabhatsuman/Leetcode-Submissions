class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())return false;
        vector<vector<int>> dp(s1.length()+1,vector<int> (s2.length()+1,-1));
        
        function<bool(int,int ,int)>helper =[&](int i,int j,int k)
        {
            if(k==s3.length())
            {
                return true;
            }
            if(i==s1.length() && j==s2.length())
            {
                return false;
            }
            if(dp[i][j]!=-1)
            {
                return (bool)dp[i][j];
            }
            bool ans=false;
            if(s1[i]==s3[k])
            {
                ans|=helper(i+1,j,i+j+1);
            }
            if(s2[j]==s3[k])
            {
                ans|=helper(i,j+1,i+j+1);
            }
            dp[i][j]=ans;
            return ans;

        };
        return helper(0,0,0);
    }
};
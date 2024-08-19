class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        function<int(int,int)> helper=[&](int left,int right)
        {
            if(left>right)
            {
                return 0;
            }
            if(dp[left][right]!=-1)
            {
                return dp[left][right];
            }
            int ans=0;
            for(int mid=left;mid<=right;mid++)
            {
                ans=max(ans,nums[left-1]*nums[mid]*nums[right+1]+helper(left,mid-1)+helper(mid+1,right));
            }
            return dp[left][right]=ans;
        };
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        return helper(1,n);
    }
};
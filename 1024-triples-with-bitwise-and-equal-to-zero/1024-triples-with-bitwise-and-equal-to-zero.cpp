class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<vector<int>> dp(4,vector<int>(1<<16,-1));
        function<int(int,int)> helper=[&](int count,int curr)
        {
            if(count==0 && curr==0)
            {
                return 1;
            }
            else if(count==0)
            {
               
                return 0;
            }
            if(dp[count][curr]!=-1)
            {
                return dp[count][curr];
            }
            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
                sum+=helper(max(0,count-1),curr&nums[i]);
            }
            return dp[count][curr]= sum;
        };
        return helper(3,(1<<16)-1);
    }
};
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n=nums1.size();
        int dp[100005][2];
        memset(dp,-1,sizeof(dp));
        function<int(int,int)>helper=[&](int ind,int isSwapped)
        {   
            if(ind==n)
            {
                return 0;
            }
            if(dp[ind][isSwapped]!=-1)return dp[ind][isSwapped];
            int prev1=nums1[ind-1];
            int prev2=nums2[ind-1];
            if(isSwapped)
            {
                swap(prev1,prev2);
            }
            int ans=1e9;
            if(prev1<nums1[ind] && prev2<nums2[ind])
            {
                ans=min(ans,helper(ind+1,0));
            }
            if(prev1<nums2[ind] && prev2<nums1[ind])
            {
                ans=min(ans,helper(ind+1,1)+1);
            }
            return dp[ind][isSwapped]= ans;
        };
        return helper(1,0);
    }
};
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {        
        sort(arr2.begin(),arr2.end());
        unordered_map<int,unordered_map<int,int>>dp;
        function<int(int,int)> helper=[&](int ind ,int prev)
        {
            if(ind==arr1.size())
            {
                return 0;
            }
            if(dp.count(ind) && dp[ind].count(prev))
            {
                return dp[ind][prev];
            }
            int ans=1e9;
            if(prev<arr1[ind])
            {
                ans=min(ans,helper(ind+1,arr1[ind]));
            }
            int newInd=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
            if(newInd<arr2.size())
            {
                ans=min(ans,helper(ind+1,arr2[newInd])+1);
            }
            return dp[ind][prev]=ans;
        };
        int ans=helper(0,-1);
        return ans==1e9?-1:ans;

    }
};
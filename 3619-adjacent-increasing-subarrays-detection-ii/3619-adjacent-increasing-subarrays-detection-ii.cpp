class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int len=1;
        int n=nums.size();
        vector<int> v;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                len++;
            }
            else
            {
                v.push_back(len);
                len=1;
            }
        }
        v.push_back(len);
        int ans=0;
        for(auto it:v)
        {
            cout<<it<<" ";
        }
        for(int i=0;i<v.size()-1;i++)
        {
            ans=max(ans,min(v[i],v[i+1]));
            ans=max(ans,v[i]/2);
        }
        ans=max(ans,v.back()/2);
        return ans;
    }
};
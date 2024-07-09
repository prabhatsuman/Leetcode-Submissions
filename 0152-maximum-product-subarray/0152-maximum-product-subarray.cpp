class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int minProd=nums[0],maxProd=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int it=nums[i];
            int temp=maxProd;
            maxProd=max({it,it*maxProd,it*minProd});
            minProd=min({it,it*minProd,it*temp});
            ans=max(ans,maxProd);
        }
        return ans;
    }
};
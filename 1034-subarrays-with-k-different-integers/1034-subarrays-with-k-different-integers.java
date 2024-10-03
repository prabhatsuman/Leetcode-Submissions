class Solution {
    int [] nums;    
    int n;
    public int helper(int k)
    {
        int left=0,right=0;
        int ans=0;
        Map<Integer,Integer> mp= new HashMap<>();
        while(right<n)
        {
            mp.put(nums[right],mp.getOrDefault(nums[right],0)+1);
            while(mp.size()>k)
            {
                mp.put(nums[left],mp.get(nums[left])-1);
                if(mp.get(nums[left])==0)
                {
                    mp.remove(nums[left]);
                }
                left++;
            }
            ans+=right-left+1;
            right++;          
        }
        return ans;
        
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        this.nums=nums;
        n=nums.length;
        return helper(k)-helper(k-1);
        
    }
}
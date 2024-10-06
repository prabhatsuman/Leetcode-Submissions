class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int low = 0, high = n - 1;
        
        
        if (nums[low] <= nums[high]) {
            return nums[low];
        }
        
        
        while (high - low > 1) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return nums[high];
    }
}

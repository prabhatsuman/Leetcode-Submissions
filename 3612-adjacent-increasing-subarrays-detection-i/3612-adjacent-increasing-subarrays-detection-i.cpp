class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; i++) {
            bool flag = true;
            // Check if the first subarray of length k is strictly increasing
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    flag = false;
                    break;
                }
            }
            // Check if the second subarray of length k is strictly increasing
            for (int j = i + k; j < i + 2 * k - 1 && flag; j++) {
                if (nums[j] >= nums[j + 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};

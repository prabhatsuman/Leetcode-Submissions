class Solution {

    public int countOfPairs(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int[][] dp = new int[n + 1][1001];

        for (int i = 0; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            int prev = 0;
            int ways = 0;
            for (int curr = 0; curr <= nums[i]; curr++) {
                if (prev <= Math.min(curr, curr - nums[i] + nums[i - 1])) {
                    ways = (ways + dp[i - 1][prev]) % mod;
                    prev++;
                }
                dp[i][curr] = ways;
            }
        }
        int ans = 0;
        for (int i = 0; i <= 1000; i++) {
            ans = (ans + dp[n - 1][i]) % mod;
        }
        return ans;
    }
}

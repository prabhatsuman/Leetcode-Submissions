class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> dp;

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(51, - 1));

        function<int(int, int)> helper = [&](int ind, int last1) {
            if (ind == n) {
                return 1;
            }
            if (dp[ind][last1] != -1) {
                return dp[ind][last1];
            }

            int count = 0;
            for (int i = 0; i <= nums[ind]; i++) {
                if (ind == 0) {
                    count = (count + helper(ind + 1, i)) % mod;

                } else {
                    if (i >= last1 && nums[ind] - i <= nums[ind - 1] - last1) {
                        count = (count + helper(ind + 1, i)) % mod;
                    }
                }
            }
            return dp[ind][last1] = count;
        };

        return helper(0, 0);
    }
};

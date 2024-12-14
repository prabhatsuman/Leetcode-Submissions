#include <vector>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        // If the total number of stones cannot be reduced to one pile, return -1.
        if ((n - 1) % (k - 1) != 0) return -1;

        // Prefix sum to calculate the sum of any subarray efficiently.
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + stones[i - 1];
        }

        // Memoization table: dp[left][right][piles]
        int dp[31][31][31]; // Max constraints of n = 30
        memset(dp, -1, sizeof(dp));

        // Helper function for memoized recursion.
        function<int(int, int, int)> dfs = [&](int left, int right, int piles) -> int {
            // Base case: If we are at a single pile, the cost is 0.
            if (left == right) return (piles == 1) ? 0 : 1e9;

            // If the result is already computed, return it.
            if (dp[left][right][piles] != -1) return dp[left][right][piles];

            int res = 1e9;
            if (piles == 1) {
                // Merge the entire range [left, right] into one pile.
                res = dfs(left, right, k) + preSum[right + 1] - preSum[left];
            } else {
                // Split the range into smaller subproblems.
                for (int mid = left; mid < right; mid++) {
                    res = min(res, dfs(left, mid, 1) + dfs(mid + 1, right, piles - 1));
                }
            }

            return dp[left][right][piles] = res;
        };

        // Solve for the entire range [0, n-1] and reduce to 1 pile.
        return dfs(0, n - 1, 1);
    }
};

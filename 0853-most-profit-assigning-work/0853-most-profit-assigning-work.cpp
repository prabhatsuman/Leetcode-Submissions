class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {difficulty[i], profit[i]};
        }

        // Sort by difficulty first and if equal, then by profit in descending order
        sort(v.begin(), v.end());

        // To keep the max profit till current difficulty
        for (int i = 1; i < n; i++) {
            v[i].second = max(v[i].second, v[i - 1].second);
        }

        // Sort workers to assign the best jobs in order
        sort(worker.begin(), worker.end());

        int ans = 0, j = 0;
        for (int ability : worker) {
            while (j < n && ability >= v[j].first) {
                j++;
            }
            if (j > 0) {
                ans += v[j - 1].second;
            }
        }
        return ans;
    }
};

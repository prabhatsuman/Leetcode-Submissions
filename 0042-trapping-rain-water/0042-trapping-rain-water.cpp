class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if (n <= 2) return 0; // Trapping water is not possible with less than 3 bars

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        leftMax[0] = heights[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], heights[i]);
        }

        rightMax[n - 1] = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], heights[i]);
        }

        int trappedWater = 0;
        for (int i = 1; i < n - 1; i++) {
            trappedWater += max(0, min(leftMax[i], rightMax[i]) - heights[i]);
        }

        return trappedWater;
    }
};
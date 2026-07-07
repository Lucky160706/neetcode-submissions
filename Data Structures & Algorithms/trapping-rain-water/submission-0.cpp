class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int maxHeight = 0;
        long long totalBars = 0;
        for (int i = 0; i < n; i++) {
            maxHeight = max(maxHeight, height[i]);
            totalBars += height[i];
        }

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        long long totalSpilled = 0;
        for (int i = 0; i < n; i++) {
            int waterLevel = min(leftMax[i], rightMax[i]);
            totalSpilled += (maxHeight - waterLevel);
        }
        return (n * maxHeight) - totalBars - totalSpilled;
    }
};

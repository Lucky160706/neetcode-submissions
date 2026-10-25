class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int ans = INT_MAX;
            for (int j = i + 1; j <= min(n - 1, i + nums[i]); ++j) {
                if (dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        return dp[0];
    }
};

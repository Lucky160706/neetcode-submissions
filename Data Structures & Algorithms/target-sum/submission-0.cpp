class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > S || (S - target) % 2 != 0) {
            return 0;
        }

        int n = (S - target) / 2;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int& x : nums) {
            for (int s = n; s >= x; s--) {
                dp[s] += dp[s - x];
            }
        }

        return dp[n];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int res = prices[0];
        int n = prices.size();

        vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i - 1] > prices[i] - res) {
                profit += dp[i - 1];
                res = prices[i];
                dp[i - 1] = 0;
            } else {
                dp[i] = max(prices[i] - res, dp[i - 1]);
                res = min(res, prices[i]);
            }
        }
        if (dp[n - 1] != 0) {
            profit += dp[n - 1];
        }
        return profit;
    }
};
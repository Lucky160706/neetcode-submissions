class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = prices[0];
        int n = prices.size();
        int max_profit = 0;
        for (int i = 1; i < n; i++) {
            res = min(res, prices[i]);
            max_profit = max(prices[i] - res, max_profit);
        }
        return max_profit;
    }
};

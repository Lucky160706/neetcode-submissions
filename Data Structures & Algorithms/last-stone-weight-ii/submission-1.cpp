class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int S = accumulate(stones.begin(), stones.end(), 0);

        vector<int> dp(S / 2 + 1, 0);

        dp[0] = 1;

        for (int& x : stones) {
            for (int j = S / 2; j >= x; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }

        for (int i = S / 2; i >= 0; i--) {
            if (dp[i]) return S - 2 * i;
        }
        return 0;
    }
};
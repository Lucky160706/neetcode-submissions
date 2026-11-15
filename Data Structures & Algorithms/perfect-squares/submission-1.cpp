class Solution {
public:
    bool check(int n) {
        int root = sqrt(n);
        return root * root == n;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        vector<int> perfectSquare;

        for (int i = 1; i <= n; i++) {
            if (check(i)) {
                dp[i] = 1;
                perfectSquare.push_back(i);
            }
            else {
                for (int j = perfectSquare.size() - 1; j >= 0; j--) {
                    dp[i] = min(dp[i - perfectSquare[j]] + dp[perfectSquare[j]], dp[i]);
                }
            }
        }

        return dp[n];
    }
};
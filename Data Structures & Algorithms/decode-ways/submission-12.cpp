class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int n = s.size();

        vector<int> dp(n, 0);

        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            string two_char = s.substr(i - 1, 2);
            int nums = stoi(two_char);
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }

            // Decode two digits
            if (nums >= 10 && nums <= 26) {
                dp[i] += (i >= 2 ? dp[i - 2] : 1);
            }
        }

        return dp[n - 1];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int lenWord1 = word1.size();
        int lenWord2 = word2.size();

        if (lenWord1 == 0) {
            return lenWord2;
        } else if (lenWord2 == 0) {
            return lenWord1;
        }

        vector<vector<int>> dp(lenWord1 + 1, vector<int>(lenWord2 + 1, 0));

        for (int i = 0; i <= lenWord1; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= lenWord2; j++) {
            dp[0][j] = j;
        }   

        for (int i = 1; i <= lenWord1; i++) {
            for (int j = 1; j <= lenWord2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }

        return dp[lenWord1][lenWord2];
    }
};

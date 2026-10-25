class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(text1, text2, 0, 0, memo);
    }

    int dfs(string& text1, string& text2, int i, int j, vector<vector<int>>& memo) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        if (text1[i] == text2[j]) {
            return 1 + dfs(text1, text2, i + 1, j + 1, memo);
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int skip_char_text1 = dfs(text1, text2, i + 1, j, memo);
        int skip_char_text2 = dfs(text1, text2, i, j + 1, memo);

        return memo[i][j] = max(skip_char_text1, skip_char_text2);
    }
};

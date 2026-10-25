class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se (wordDict.begin(), wordDict.end());

        vector<int> memo(s.size(), -1);

        return dfs(s, 0, se, memo);
    }

    bool dfs(string& s, int i, unordered_set<string>& se, vector<int>& memo) {

        if (i == s.size()) {
            return true;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        for (int j = i; j < s.size(); ++j) {
            string word = s.substr(i, j - i + 1);

            if (se.count(word)) {
                if (dfs(s, j + 1, se, memo)) {
                    return memo[i] = true;
                }
            }
        }

        return memo[i] = false;

    }
};

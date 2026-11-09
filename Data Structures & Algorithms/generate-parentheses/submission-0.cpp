class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string res = "";

        backtrack(ans, res, n, 0, 0);

        return ans;
    }

    void backtrack(vector<string>& ans, string& res, int n, int open, int close) {
        if (open == n && close == n) {
            ans.push_back(res);
            return ;
        }

        if (open < n) {
            res.push_back('(');
            backtrack(ans, res, n, open + 1, close);
            res.pop_back();
        }
        if (close < open) {
            res.push_back(')');
            backtrack(ans, res, n, open, close + 1);
            res.pop_back();
        }
    }
};

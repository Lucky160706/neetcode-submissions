class Solution {
public:
    vector<int> pascal(vector<int> res) {
        vector<int> ans;
        int n = res.size();
        ans.push_back(res[0]);
        for (int i = 0; i < n - 1; i++) {
            ans.push_back(res[i] + res[i + 1]);
        }
        ans.push_back(res[n - 1]);
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        } else if (numRows == 2) {
            return {{1}, {1, 1}};
        }
        vector<vector<int>> ans {{1}, {1, 1}};
        for (int i = 2; i < numRows; i++) {
            ans.push_back(pascal(ans[i - 1]));
        }
        return ans;
    }
};
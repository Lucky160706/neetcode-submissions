class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        int total = 0;
        int n;
        for (int i = 0; i < operations.size(); i++) {
            n = ans.size();
            if (operations[i] == "+") {
                ans.push_back(ans[n - 2] + ans[n - 1]);
            } else if (operations[i] == "C") {
                ans.pop_back();
            } else if (operations[i] == "D") {
                ans.push_back(ans[n - 1] * 2);
            } else {
                ans.push_back(stoi(operations[i]));
            }
        }
        for (int &num : ans) {
            total += num;
        }
        return total;
    }
};
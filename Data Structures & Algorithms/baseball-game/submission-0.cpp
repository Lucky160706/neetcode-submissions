class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<long long> ans;
        long long total = 0;
        for (int i = 0; i < operations.size(); i++) {
            int n = ans.size();
            if (operations[i] == "+") {
                ans.push_back(ans[n - 2] + ans[n - 1]);
            } else if (operations[i] == "C") {
                ans.pop_back();
            } else if (operations[i] == "D") {
                ans.push_back(ans[n - 1] * 2);
            } else {
                ans.push_back(stol(operations[i]));
            }
            for (long long &num : ans) {
                cout << num << " ";
            }
            cout << "=========\n";
        }
        for (long long &num : ans) {
            total += num;
        }
        return total;
    }
};
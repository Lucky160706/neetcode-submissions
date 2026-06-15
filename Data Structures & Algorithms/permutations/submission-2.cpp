class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int const& n = nums.size();

        vector<int> path;
        vector<vector<int>> ans;
        vector<bool> visited(n, false);


        function<void()> dfs = [&]() {
            if (path.size() == n) {
                ans.push_back(path);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (visited[i] == false) {
                    path.push_back(nums[i]);
                    visited[i] = true;
                    dfs();
                    path.pop_back();
                    visited[i] = false;
                }
                else {
                    continue;
                }
            }

        };

        dfs();
        return ans;
    }
};

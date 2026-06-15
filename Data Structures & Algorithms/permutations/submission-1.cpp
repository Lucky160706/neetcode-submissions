class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;

        set<int> sett;

        int const& n = nums.size();

        function<void(int)> dfs = [&](int index) {
            if (path.size() == n) {
                ans.push_back(path);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (sett.find(nums[i]) == sett.end()) {
                    path.push_back(nums[i]);
                    sett.insert(nums[i]);
                    dfs(i + 1);
                    path.pop_back();
                  sett.erase(nums[i]);
                }
                else {
                    continue;
                }
                // dfs(i + 1);
            }

        };

        dfs(0);
        return ans;
    }
};

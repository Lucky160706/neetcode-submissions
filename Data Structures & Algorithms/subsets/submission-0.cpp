class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int)> backtrack = [&](int index) {
            if (index == nums.size()) {
                ans.push_back(path);
                return ;
            }

            path.push_back(nums[index]);
            backtrack(index + 1);
            path.pop_back();

            backtrack(index + 1);
        };

        backtrack(0);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        int total = 0;

        function<void(int)> backtrack = [&](int index) {
            if (total == target) {
                res.push_back(path);
                return ;
            }
            if (index == nums.size() || total > target) {
                return ;
            }

            path.push_back(nums[index]);
            total += nums[index];
            backtrack(index);
            path.pop_back();
            total -= nums[index];

            backtrack(index + 1);
        };

        backtrack(0);
        return res;
    }
};
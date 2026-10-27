class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (total_sum % 2 != 0) return false;

        int target = total_sum / 2;

        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));

        return dfs(nums, 0, 0, target, memo);
    }

    bool dfs(vector<int>& nums, int sum, int i, int target, vector<vector<int>>& memo) {

        if (target == sum) {
            return true;
        }

        if (sum > target || i >= nums.size()) return false;

        if (memo[i][sum] != -1) {
            return memo[i][sum];
        }

        bool take = dfs(nums, sum + nums[i], i + 1, target, memo);
        bool skip = dfs(nums, sum, i + 1, target, memo);

        return memo[i][sum] = take || skip;
    }
};

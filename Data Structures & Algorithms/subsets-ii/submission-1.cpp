class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;

        sort(nums.begin(), nums.end());

        function<void(int)> backtrack = [&](int index) {
            ans.push_back(path);
            if (index == nums.size()) {
                return ;
            }

            for (int i = index; i < nums.size(); i++) {
                if (i > index && nums[i] == nums[i - 1]) continue;
                path.push_back(nums[i]);
                backtrack(i + 1);
                path.pop_back();
            }
            
        };

        backtrack(0);
        return ans;
    }
};

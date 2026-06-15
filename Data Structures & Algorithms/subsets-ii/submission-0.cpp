class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        set<vector<int>> sett;

        function<void(int)> backtrack = [&](int index) {
            if (index == nums.size()) {
                vector<int> sorted_path = path;
                sort(sorted_path.begin(), sorted_path.end());

                if (sett.find(sorted_path) == sett.end()) {
                    sett.insert(sorted_path);
                    ans.push_back(path);
                }
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

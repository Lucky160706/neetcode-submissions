class Solution {
public:

    int calculateXOR(vector<int>& res) {
        int total = 0;
        for (int i = 0; i < res.size(); i++) {
            total ^= res[i];
        }
        return total;
    }

    int subsetXORSum(vector<int>& nums) {
        // Total of XOR 
        int ans = 0;

        // Save the subset
        vector<int> res;

        backtrack(nums, res, 0, &ans);

        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& res, int index, int* ans) {
        

        if (index == nums.size()) {
            *ans += calculateXOR(res);
            return; 
        }


        res.push_back(nums[index]);

        backtrack(nums, res, index + 1, ans);

        res.pop_back();

        backtrack(nums, res, index + 1, ans);
    }
    
};
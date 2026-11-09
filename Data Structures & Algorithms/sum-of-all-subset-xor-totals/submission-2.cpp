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

        int current_xor = 0;

        // Save the subset
        vector<int> res;

        backtrack(nums, res, 0, &ans, &current_xor);

        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& res, int index, int* ans, int* current_xor) {
        

        if (index == nums.size()) {
            *ans += *current_xor;
            return; 
        }


        res.push_back(nums[index]);

        *current_xor ^= nums[index];

        backtrack(nums, res, index + 1, ans, current_xor);

        res.pop_back();

        *current_xor ^= nums[index];

        backtrack(nums, res, index + 1, ans, current_xor);
    }
    
};
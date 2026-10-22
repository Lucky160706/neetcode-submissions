class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int prev1 = 0; 
        int prev2 = 0;

        int skipHouse0;

        for (int i = n - 1; i >= 1; --i) {
            skipHouse0 = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = skipHouse0;
        }

        int robHouse0;
        prev1 = 0;
        prev2 = 0;

        for (int i = n - 2; i >= 0; --i) {
            robHouse0 = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = robHouse0;
        }

        return max(robHouse0, skipHouse0);
    }
};

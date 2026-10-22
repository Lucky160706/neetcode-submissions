class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = 0;

        int curr;

        for (int i = n - 1; i >= 0; --i) {
            curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

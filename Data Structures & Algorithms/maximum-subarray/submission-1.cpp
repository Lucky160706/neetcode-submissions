class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int l = 0;
        int total = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            total += nums[i];

            if (total < nums[i]) {
                while (total < nums[i]) {
                    total -= nums[l];
                    l++;
                }
            }

            ans = max(total, ans);
        }

        return ans;
    }
};

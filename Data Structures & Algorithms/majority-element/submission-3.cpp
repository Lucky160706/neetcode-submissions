class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int count = 1;
        sort(nums.begin(), nums.end());
        int ans = nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                count++;
                if (count > nums.size() / 2) {
                    ans = nums[i];
                    break; 
                }
            } else {
                count = 1;
            }
        }
        return ans;
    }
};
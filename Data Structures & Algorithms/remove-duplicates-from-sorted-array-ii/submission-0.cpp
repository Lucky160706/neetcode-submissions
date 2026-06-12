class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int ans = 1;
        int k = 1;
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (res != nums[i]) {
                k = 1;
                res = nums[i];
                ans++;
            } else {
                if (k < 2) {
                    k++;
                    ans++;
                } else {
                    nums[i] = 100001;
                }
            }
        }
        sort(nums.begin(), nums.end());
        return ans;
    }
};
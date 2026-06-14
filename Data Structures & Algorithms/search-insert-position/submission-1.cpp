class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int cnt = 0;

        for (int num : nums) {
            if (num < target) {
                cnt++;
            }
        }
        return cnt;
    }
};
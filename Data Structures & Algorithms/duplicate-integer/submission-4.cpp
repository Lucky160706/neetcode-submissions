class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> sett;
        for (int i = 0; i < nums.size(); i++) {
            if (sett.find(nums[i]) == sett.end()) {
                sett.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> path;
        int total = 0;

        function<int(vector<int>)> calc_xor = [&](vector<int> res) {
            int xor_total = 0;
            for (int num : res) {
                xor_total ^= num; // Accumulate using bitwise XOR
            }
            return xor_total;
        };

        function<void(int)> backtrack = [&](int index) {
            if (index == nums.size()) {
                total += calc_xor(path);
                return;
            }

            path.push_back(nums[index]);
            backtrack(index + 1);
            path.pop_back();

            backtrack(index + 1);
        };

        backtrack(0);
        return total;
    }
};
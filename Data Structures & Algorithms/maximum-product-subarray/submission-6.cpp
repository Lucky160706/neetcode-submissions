class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int curMax = 1;
        int curMin = 1;

        int ans = *max_element(nums.begin(), nums.end());

        for (int x : nums) {
            if (x == 0) {
                curMax = 1;
                curMin = 1;
                continue;
            }

            int tmp = curMax * x;

            curMax = max({x, curMax * x, curMin * x});
            curMin = min({x, tmp, curMin * x});

            ans = max(ans, curMax);
        }

        return ans;
    }
};

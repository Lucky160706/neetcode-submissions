class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n, 1);
        vector<int> dpMin(n, 1);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; ++i) {
            if (nums[i] == 0) {
                dpMax[i] = 0;
                dpMin[i] = 0;
            } else {
                dpMax[i] = max({nums[i],
                            dpMax[i - 1] * nums[i],
                            dpMin[i - 1] * nums[i]
            });
                dpMin[i] = min({nums[i],
                            dpMax[i - 1] * nums[i],
                            dpMin[i - 1] * nums[i]
            });
            }
                ans = max(ans, dpMax[i]);

        }

        return ans;
    }
};

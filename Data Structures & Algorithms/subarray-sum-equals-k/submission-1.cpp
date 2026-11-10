class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;

        unordered_map<int, int> mp;

        vector<int> prefixSum(n + 1, 0);        

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        // Empty prefix
        mp[0] = 1;

        // Count valid subarrays
        for (int i = 1; i <= n; i++) {
            int target = prefixSum[i] - k;

            ans += mp[target];

            mp[prefixSum[i]]++;
        }
        return ans;
    }
};
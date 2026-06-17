class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> arr(n + 1);
        for (int i = 2; i <= n; i++) {
            arr[i] = min(arr[i - 1] + cost[i - 1], arr[i - 2] + cost[i - 2]);
        }  
        return arr[n];
    }
};

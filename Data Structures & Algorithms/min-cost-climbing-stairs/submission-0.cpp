class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> arr(n + 1);
        arr[0] = cost[0];
        arr[1] = cost[1];
        arr[n] = 0;
        for (int i = 2; i <= n; i++) {
            if (i == n) {
                arr[i] = min(arr[i - 2], arr[i - 1]);
            } else {
                arr[i] = min(arr[i - 2], arr[i - 1]) + cost[i];
            }
        }  
        return arr[n];
    }
};

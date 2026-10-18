class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq(nums.begin(), nums.end());

        while (k > 1) {
            // int ans = pq.top();
            pq.pop();
            k--;
        }
        return pq.top();
    }
};

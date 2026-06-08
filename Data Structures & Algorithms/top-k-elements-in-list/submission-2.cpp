class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashmap;
        for (int num : nums) {
            if (hashmap.count(num)) {
                hashmap[num]++;
            } else {
                hashmap[num] = 1;
            }
        }
        vector<pair<int, int>> sortedVector(hashmap.begin(), hashmap.end());
        sort(sortedVector.begin(), sortedVector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; 
        });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(sortedVector[i].first);
        }
        return ans;
    }
};
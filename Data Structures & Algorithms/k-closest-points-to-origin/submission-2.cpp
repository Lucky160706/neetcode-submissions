class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto minHeapComp = [](vector<int> p1, vector<int> p2) {
            return sqrt(pow(p1[0], 2) + pow(p1[1], 2)) > sqrt(pow(p2[0], 2) + pow(p2[1], 2));
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(minHeapComp)> pq(minHeapComp);

        for (auto it : points) pq.push(it);

        vector<vector<int>> ans;

        while (k--) {
            vector<int> res = pq.top();
            pq.pop();

            ans.push_back(res);
        }

        return ans;
    }
};

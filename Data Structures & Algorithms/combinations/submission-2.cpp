class Solution {
public:
    void combination(int index, int& n, int& k, vector<vector<int>>& ans, vector<int>& path) {  
            if (path.size() == k) {
                ans.push_back(path);
                return;
            }

            for (int i = index + 1; i <= n; i++) {
                path.push_back(i);
                combination(i , n, k, ans, path);
                path.pop_back();
            }
        }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        
        // Declare a lambda function that captures everything by reference [&]
        function<void(int)> dfs = [&](int index) {
            if (path.size() == k) {
                ans.push_back(path);
                return;
            }
            for (int i = index + 1; i <= n; i++) {
                path.push_back(i);
                dfs(i);          // Only need to pass the index now!
                path.pop_back();
            }
        };
        
        dfs(0); 
        return ans;
    }
};
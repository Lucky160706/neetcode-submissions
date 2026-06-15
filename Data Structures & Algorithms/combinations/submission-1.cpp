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
        
        combination(0, n, k, ans, path);

        return ans;
    }
};
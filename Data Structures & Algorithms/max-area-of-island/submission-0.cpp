class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int area = dfs(grid, i, j);
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 ||
            i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;

        int ans = 1;
        ans += dfs(grid, i + 1, j);
        ans += dfs(grid, i - 1, j);
        ans += dfs(grid, i, j + 1);
        ans += dfs(grid, i, j - 1);

        return ans;
    }

private:
    int m;
    int n;
};

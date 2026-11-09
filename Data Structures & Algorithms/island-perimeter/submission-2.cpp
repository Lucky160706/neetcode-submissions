class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        set<pair<int, int>> visited;


        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    return dfs(grid, i, j, visited);
                }
            }
        }
    }

    int dfs(vector<vector<int>>& grid, int i , int j, set<pair<int, int>>& visited) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == 0) {
            return 1;
        }

        if (visited.find({i, j}) != visited.end()) {
            return 0;
        }

        visited.insert({i, j});

        int perim = dfs(grid, i, j + 1, visited);
        perim += dfs(grid, i, j - 1, visited);
        perim += dfs(grid, i + 1, j, visited);
        perim += dfs(grid, i - 1, j, visited);

        return perim;
    }
};
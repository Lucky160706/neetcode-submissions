class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Number of rotted orange
        int rotted_orange = 0;

        // Total number of orange
        int total_orange = 0;

        // Time
        int time = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    rotted_orange++;
                    total_orange++;
                } else if (grid[i][j] == 1) {
                    total_orange++;
                }
            }
        }

        if (rotted_orange == total_orange) return 0;

        while (!q.empty()) {
            int temp = q.size();
            bool changed = false;

            for (int i = 0; i < temp; i++) {
                pair<int, int> curr = q.front();
                q.pop();

                int row = curr.first;
                int col = curr.second;

                if (row + 1 < m && grid[row + 1][col] == 1) {
                    q.push({row + 1, col});
                    grid[row + 1][col] = 2;
                    rotted_orange++;
                    changed = true;
                }

                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    q.push({row - 1, col});
                    grid[row - 1][col] = 2;
                    rotted_orange++;
                    changed = true;
                }

                if (col + 1 < n && grid[row][col + 1] == 1) {
                    q.push({row, col + 1});
                    grid[row][col + 1] = 2;
                    rotted_orange++;
                    changed = true;
                }

                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    q.push({row, col - 1});
                    grid[row][col - 1] = 2;
                    rotted_orange++;
                    changed = true;
                }
            }
            if (changed) {
                time++;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
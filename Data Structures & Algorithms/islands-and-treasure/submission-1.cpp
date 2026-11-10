class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {-1, 1, 0, 0};

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Step 1: Push all gates into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int distance = 0;


        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                // TODO 1: Check boundaries
                if (nr < 0 || nc < 0 || nc >= n || nr >= m) continue;

                // TODO 2: If rooms[nr][nc] == INT_MAX:
                //   update its distance
                //   push it into queue
                if (grid[nr][nc] == INT_MAX) {
                    // rooms[row][col] lưu luôn khoảng cách đến gate
                    grid[nr][nc] = grid[row][col] + 1;
                    q.push({nr, nc});
                }
            }
            
            distance++;
        }
    }
};

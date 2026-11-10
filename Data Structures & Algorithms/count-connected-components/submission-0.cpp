class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);

        int ans = 0;

        vector<vector<int>> adj(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(adj, i, visited);
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
};

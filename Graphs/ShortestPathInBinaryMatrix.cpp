class Solution {
  public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        dist[0][0] = 1;

        // q <- {dist, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
        vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto it = q.front(); q.pop();
            int cost = it.first;
            int row = it.second.first, col = it.second.second;

            // Early exit
            if (row == n - 1 && col == n - 1) return dist[row][col];

            for (int k = 0; k < 8; k++) {
                int i = row + dx[k];
                int j = col + dy[k];

                if (i >= 0 && i < n && j >= 0 && j < n &&
                    grid[i][j] == 0 && dist[i][j] > cost + 1) {
                    q.push({cost + 1, {i, j}});
                    dist[i][j] = cost + 1;
                }   
            }
        }

        if (dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];
    }
};

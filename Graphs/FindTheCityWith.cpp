class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX)); // distacency Matrix
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Using Floyd Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (dist[i][k] == INT_MAX) continue;
                for (int j = 0; j < n; j++) {
                    if (dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int resCity = -1, minCities = n;
        for (int i = 0; i < n; i++) {
            int cities = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) cities++;
            }
            if (cities <= minCities) {
                minCities = cities;
                resCity = i;
            }
        }
        return resCity;
    }
};

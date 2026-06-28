// https://leetcode.com/problems/path-with-minimum-effort/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;

        // pq <- {dist, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});

        vector<int> dx = {-1, 0, 1 ,0};
        vector<int> dy = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int cost = it.first;
            int row = it.second.first, col = it.second.second;

            // Lazy Deletion
            if (cost > dist[row][col]) continue;

            // Early Exit
            if (row == m-1 && col == n-1) return cost;

            for (int k = 0; k < 4; k++) {
                int i = row + dx[k];
                int j = col + dy[k];

                if (i >= 0 && i < m && j >= 0 && j < n) {
                    int newDist = max(cost, abs(heights[i][j] - heights[row][col]));
                    
                    if (newDist >= dist[i][j]) continue;

                    pq.push({newDist, {i, j}});
                    dist[i][j] = newDist;
                }
            }
        }

        return 0; // Unreachable
    }
};

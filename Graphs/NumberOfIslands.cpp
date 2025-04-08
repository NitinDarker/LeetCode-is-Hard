// https://leetcode.com/problems/number-of-islands/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void BFS(pair<int, int> start, vector<vector<bool>> &visited, const vector<vector<char>> &grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = true;
        while (!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();

            // Top
            if (node.first > 0 && !visited[node.first - 1][node.second] && grid[node.first][node.second] != '0') {
                q.push({node.first - 1, node.second});
                visited[node.first - 1][node.second] = true;
            }

            // Bottom
            if (node.first + 1 < ROW && !visited[node.first + 1][node.second] && grid[node.first][node.second] != '0') {
                q.push({node.first + 1, node.second});
                visited[node.first + 1][node.second] = true;
            }

            // Left
            if (node.second > 0 && !visited[node.first][node.second - 1] && grid[node.first][node.second] != '0') {
                q.push({node.first, node.second - 1});
                visited[node.first][node.second - 1] = true;
            }

            // Right
            if (node.second + 1 < COL && !visited[node.first][node.second + 1] && grid[node.first][node.second] != '0') {
                q.push({node.first, node.second + 1});
                visited[node.first][node.second + 1] = true;
            }
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
        int count = 0;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    BFS({i, j}, visited, grid);
                    count++;
                }
            }
        }
        return count;
    }
};

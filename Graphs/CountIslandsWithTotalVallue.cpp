// https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long bfs(const vector<vector<int>> &matrix, vector<vector<bool>> &visited, pair<int, int> start) {
        long long sum = 0;
        int x = start.first, y = start.second;
        queue<pair<int,int>> q;
        q.push(start);
        visited[x][y] = true;

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            sum += matrix[x][y];
            q.pop();

            if (x > 0 && matrix[x-1][y] != 0 && !visited[x-1][y]) {
                q.push({x-1, y});
                visited[x-1][y] = true;
            }
            if (x < matrix.size()-1 && matrix[x+1][y] != 0 && !visited[x+1][y]) {
                q.push({x+1, y});
                visited[x+1][y] = true;
            }
            if (y > 0 && matrix[x][y-1] != 0 && !visited[x][y-1]) {
                q.push({x, y-1});
                visited[x][y-1] = true;
            }
            if (y < matrix[0].size()-1 && matrix[x][y+1] != 0 && !visited[x][y+1]) {
                q.push({x, y+1});
                visited[x][y+1] = true;
            }
        }
        return sum;
    }

  public:
    int countIslands(vector<vector<int>> &grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    long long islandSum = bfs(grid, visited, {i, j});
                    if (islandSum % k == 0) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

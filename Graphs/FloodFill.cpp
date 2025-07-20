// https://leetcode.com/problems/flood-fill/description/
#include <bits/stdc++.h>
using namespace std;

// BFS
class Solution {
    void bfs(vector<vector<int>> &image, pair<int,int> start, const int &color, const int init) {
        if (init == color) return;
        queue<pair<int,int>> q;
        q.push(start);
        const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        image[start.first][start.second] = color;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (const auto &d: dir) {
                int i = x + d.first;
                int j = y + d.second;
                if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size()) continue;
                if (image[i][j] == init) {
                    q.push({i, j});
                    image[i][j] = color;
                }
            }
        }
    }

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        bfs(image, {sr, sc}, color, image[sr][sc]);
        return image;
    }
};

// DFS
class Solution {
  public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int iniColor) {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) dfs(nrow, ncol, ans, image, newColor, iniColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, color, iniColor);
        return ans;
    }
};

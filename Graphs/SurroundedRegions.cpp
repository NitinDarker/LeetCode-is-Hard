// https://leetcode.com/problems/surrounded-regions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<int> dx = {-1, 0, 1, 0};
    const vector<int> dy = {0, -1, 0, 1};

    void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<char>> &board) {
        int n = board.size(), m = board[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 'X' || vis[x][y]) return;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i], vis, board);
    }

  public:
    void solve(vector<vector<char>> &board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0 && i != n-1 && j != 0 && j != m-1) continue;
                if (board[i][j] == 'O' && !vis[i][j]) dfs(i, j, vis, board);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};

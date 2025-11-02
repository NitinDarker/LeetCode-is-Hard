// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, -1));
        // -1 for not visited
        // 1 for visited/ guarded
        // 2 for guard
        // 3 for wall
        for (vector<int> &pt: walls) {
            grid[pt[0]][pt[1]] = 3;
        }    
        for (vector<int> &pt: guards) {
            grid[pt[0]][pt[1]] = 2;
        }    
        for (vector<int> &pt: guards) {
            int x = pt[0], y = pt[1];
            
            x--; // Move left
            while (x >= 0) {
                if (grid[x][y] == 2 || grid[x][y] == 3) break;
                grid[x][y] = 1;
                x--;
            }
            
            x = pt[0]+1; // Move right
            while (x < m) {
                if (grid[x][y] == 2 || grid[x][y] == 3) break;
                grid[x][y] = 1;
                x++;
            }

            x = pt[0];
            y--; // Move up
            while (y >= 0) {
                if (grid[x][y] == 2 || grid[x][y] == 3) break;
                grid[x][y] = 1;
                y--;
            }

            y = pt[1]+1; // Move down
            while (y < n) {
                if (grid[x][y] == 2 || grid[x][y] == 3) break;
                grid[x][y] = 1;
                y++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) cnt++;
            }
        }
        return cnt;
    }
};

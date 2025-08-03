// https://www.geeksforgeeks.org/problems/2-d-difference-array/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>> &mat, vector<vector<int>> &opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diff(n, vector<int> (m, 0));
        for (int i = 0; i < opr.size(); i++) {
            vector<int> op = opr[i];
            int val = op[0];
            int r1 = op[1];
            int c1 = op[2];
            int r2 = op[3];
            int c2 = op[4];
            diff[r1][c1] += val;
            if (c2 != m-1) diff[r1][c2+1] -= val;
            if (r2 != n-1) diff[r2+1][c1] -= val;
            if (r2 != n-1 && c2 != m-1) diff[r2+1][c2+1] += val;
        }
        // Row-wise prefix sum
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                diff[i][j] += diff[i][j-1];
            }
        }
        // Col-wise prefix sum
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diff[i][j] += diff[i-1][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] += diff[i][j];
            }
        }
        return mat;
    }
};

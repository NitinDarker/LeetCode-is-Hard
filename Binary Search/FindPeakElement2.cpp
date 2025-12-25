// https://leetcode.com/problems/find-a-peak-element-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findMaxInCol(int col, vector<vector<int>> &mat) {
        int n = mat.size();
        int maxInd = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][col] > mat[maxInd][col]) {
                maxInd = i;
            }
        }
        return maxInd;
    }

  public:
    vector<int> findPeakGrid(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = m-1;
        while (l <= r) {
            int col = l + (r-l)/2;
            int row = findMaxInCol(col, mat);
            int cur = mat[row][col];
            if ((col == 0 || cur >= mat[row][col-1]) && (col == m-1 || cur >= mat[row][col+1])) {
                return {row, col};
            } else if (col > 0 && cur < mat[row][col-1]) {
                r = col - 1;
            } else {
                l = col + 1;
            }
        }
        return {-1, -1};
    }
};

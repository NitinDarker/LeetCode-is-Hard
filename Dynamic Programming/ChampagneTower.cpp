// https://leetcode.com/problems/champagne-tower/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    double f(int row, int col, int poured, vector<vector<double>> &dp) {
        if (row < col || col < 0) return 0;     
        if (dp[row][col] != -1) return dp[row][col];
        if (row == 0) {
            return dp[row][col] = (poured-1)/2.0;
        }
        double topLeft = f(row - 1, col - 1, poured, dp);
        double topRight = f(row - 1, col, poured, dp) ;
        if (topLeft < 0) topLeft = 0;
        if (topRight < 0) topRight = 0;
        return dp[row][col] = (topLeft + topRight - 1) > 0 ? ((topLeft + topRight - 1) / 2.0) : 0;
    }

  public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) return 0;
        if (query_row == 0) return poured >= 1 ? 1 : 0;
        int rows = query_row + 1;
        vector<vector<double>> dp(rows, vector<double>(rows, -1));
        return min(1.0, f(query_row - 1, query_glass - 1, poured, dp) + f(query_row - 1, query_glass, poured, dp));
    }
};
